// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int64 MOD = 1e15 + 7; 

struct Matrix {
    int64 val[4][4];
    Matrix operator * (Matrix);
    Matrix operator ^ (int64);
} Base, First;

int64 Mul(int64 a, int64 b);

Matrix Matrix::operator * (Matrix other) {
    Matrix mul;
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++) {
            mul.val[r][c] = 0;
            for (int k = 0; k < 4; k++) 
                mul.val[r][c] += Mul(val[r][k], other.val[k][c]), mul.val[r][c] %= MOD;
        }
    return mul;
}

Matrix Matrix::operator ^ (int64 exp) {
    if (exp == 1) return *this;
    Matrix half = (*this) ^ (exp / 2);
    if (exp & 1) return half * half * (*this);
    return half * half;
}

int64 Mul(int64 a, int64 b) {
    if (!b) return 0;
    int64 half = Mul(a, b / 2);
    if (b & 1) return (half * 2 + a) % MOD;
    return half * 2 % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    Base = {0, 0, 1, 1,
            1, 0, 1, 1,
            0, 1, 1, 1,
            0, 0, 0, 1};
    First = {1, 2, 3, 6};

    int t, n;
    for (cin >> t; t--;) {
        cin >> n;
        if (n == 1) cout << "1\n";
        if (n == 2) cout << "3\n";
        if (n == 3) cout << "6\n";
        if (n > 3) cout << (First * (Base ^ (n - 3))).val[0][3] << "\n";
    }
}