// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MAX_CH 62
#define LOG 62 
#define MOD (int64)(1e9+7)

struct Matrix {
    int num_row;
    int64 val[MAX_CH][MAX_CH];

    Matrix operator * (Matrix);
    Matrix operator ^ (int64);
    void operator = (Matrix);
} Base, First, Pow[LOG];

Matrix Matrix::operator * (Matrix other) {
    Matrix mul;
    mul.num_row = num_row;
    for (int r = 0; r < num_row; r++)
        for (int c = 0; c < MAX_CH; c++) {
            mul.val[r][c] = 0;
            for (int k = 0; k < MAX_CH; k++) 
                mul.val[r][c] += val[r][k] * other.val[k][c], mul.val[r][c] %= MOD;
        }
    return mul;
}

Matrix Matrix::operator ^ (int64 exp) {
    if (!exp) return *this;
    Matrix mul = *this;
    for (int64 k = LOG - 1; k >= 0; k--) 
        if (exp >= (1LL << k)) {
            mul = mul * Pow[k];
            exp -= 1LL << k;
        }
    return mul;
}

void Matrix::operator = (Matrix other) {
    num_row = other.num_row;
    for (int r = 0; r < num_row; r++)
        for (int c = 0; c < MAX_CH; c++)
            val[r][c] = other.val[r][c];
}

struct Query {
    int type;
    int64 pos;
    int ch;

    bool operator < (const Query& other) {
        return pos < other.pos;
    }
};

// Convert a character to a corresponding matrix index
int get_idx(char ch) {
    if ('0' <= ch && ch <= '9') {
        return ch - '0';
    } else if ('a' <= ch && ch <= 'z') {
        return ch - 'a' + 10;
    } else {
        return ch - 'A' + 36;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int64 n;
    int m, k;
    cin >> n >> m >> k;

    // Build Base Matrix
    Base.num_row = MAX_CH;
    for (int r = 0; r < MAX_CH; r++) 
        for (int c = 0; c < MAX_CH; c++)
            Base.val[r][c] = 1;
    while (m--) {
        char ch1, ch2;
        cin >> ch1 >> ch2;
        int idx1 = get_idx(ch1);
        int idx2 = get_idx(ch2);
        Base.val[idx1][idx2] = Base.val[idx2][idx1] = 0;
    }

    // Pre-compute Pow array: Pow[i] = (Base^2)^i
    Pow[0] = Base;
    for (int i = 1; i < LOG; i++)
        Pow[i] = Pow[i - 1] * Pow[i - 1];

    // Build First Matrix (F1)
    First.num_row = 1;
    for (int c = 0; c < MAX_CH; c++)
        First.val[0][c] = 1;

    // Preprocessing all queries
    vector<Query> queries;
    while (k--) {
        int t;
        int64 pos;
        char ch;
        cin >> t >> pos >> ch;
        queries.push_back({t, pos, get_idx(ch)});
    }
    sort(queries.begin(), queries.end());

    // Process each query
    int64 pre_pos = 1;
    for (auto [type, pos, ch]: queries) {
        First = First ^ (pos - pre_pos);
        if (!type) First.val[0][ch] = 0;
        else {
            for (int c = 0; c < MAX_CH; c++)
                if (c != ch) First.val[0][c] = 0;
        }
        pre_pos = pos;
    }
    Matrix Final = First ^ (n - pre_pos);
    int64 ans = 0;
    for (int c = 0; c < MAX_CH; c++)
        ans += Final.val[0][c];
    cout << ans % MOD << "\n";
}