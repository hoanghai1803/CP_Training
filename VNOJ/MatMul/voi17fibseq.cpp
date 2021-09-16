// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MAX_N 1000006

int T, n, k;
int64 b;
int fibo[MAX_N], pos[MAX_N];

struct Matrix {
    int val[2][2];
    Matrix operator * (Matrix);
    Matrix operator ^ (int64);
} Base, First;

Matrix Matrix::operator * (Matrix other) {
    Matrix mul;
    for (int r = 0; r < 2; r++)
        for (int c = 0; c < 2; c++) {
            mul.val[r][c] = 0;
            for (int t = 0; t < 2; t++) 
                mul.val[r][c] += 1LL * val[r][t] * other.val[t][c] % k, mul.val[r][c] %= k;
        }
    return mul;
}

Matrix Matrix::operator ^ (int64 exp) {
    if (exp == 1) return *this;
    Matrix half = (*this) ^ (exp / 2);
    if (exp & 1) return half * half * (*this);
    return half * half;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    Base = {0, 1,
            1, 1};
    First = {1, 1};

    for (cin >> T; T--;) {
        cin >> n >> b >> k;

        Matrix f = First * (Base ^ (b - 1));
        fibo[1] = f.val[0][0], fibo[2] = f.val[0][1];
        for (int i = 3; i <= n; i++) fibo[i] = (fibo[i - 1] + fibo[i - 2]) % k;

        int sum = 0;
        memset(pos, -1, sizeof(pos));
        for (int i = 1; i <= n; i++) {
            sum = (sum + fibo[i]) % k;
            if (pos[sum] != -1) {
                cout << i - pos[sum] << " ";
                for (int j = pos[sum] + 1; j <= i; j++) cout << j + b - 1 << " ";
                break;
            }
            pos[sum] = i;
        }
        cout << "\n";
    }
}