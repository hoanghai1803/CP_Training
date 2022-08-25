// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1003
#define MOD 10

struct Matrix {
    vector<vector<int>> val;

    // Constructor
    Matrix() {
        val.resize(MAX_N);
        for (int r = 0; r < MAX_N; r++)
            val[r].resize(MAX_N);
    }

    // Operators
    Matrix operator * (Matrix);
    bool operator == (Matrix);
} Base, A, B, C;

int t, n;

Matrix Matrix::operator * (Matrix other) {
    Matrix mul;
    for (int r = 0; r < 1; r++)
        for (int c = 0; c < n; c++) {
            mul.val[r][c] = 0;
            for (int k = 0; k < n; k++) 
                mul.val[r][c] += val[r][k] * other.val[k][c], mul.val[r][c] %= MOD;
        }
    return mul;
}

bool Matrix::operator == (Matrix other) {
    for (int r = 0; r < 1; r++)
        for (int c = 0; c < n; c++)
            if (val[r][c] != other.val[r][c]) return false;
    return true;
}

void enter(Matrix& M, int n) {
    string s;
    for (int r = 0; r < n; r++) {
        cin >> s;
        for (int c = 0; c < n; c++)
            M.val[r][c] = s[c] - '0';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> t; t--;) {
        cin >> n;
        for (int c = 0; c < n; c++)
            Base.val[0][c] = 1;
        enter(A, n), enter(B, n), enter(C, n);
        cout << (((Base * A) * B == Base * C) ? "YES\n" : "NO\n");
    }
}