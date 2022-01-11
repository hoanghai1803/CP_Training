// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MOD (int)(1e9 + 7)

struct Matrix {
    int val[2][2];
    Matrix operator * (Matrix);
    Matrix operator ^ (int64);
};

Matrix Matrix::operator * (Matrix other) {
    Matrix mul;
    for (int r = 0; r < 2; r++)
        for (int c = 0; c < 2; c++) {
            mul.val[r][c] = 0;
            for (int k = 0; k < 2; k++) {
                mul.val[r][c] += 1LL * val[r][k] * other.val[k][c] % MOD;
                mul.val[r][c] %= MOD;
            }
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

    Matrix First = {
        0, 1,
        0, 0
    };
    Matrix Base = {
        0, 1,
        1, 1
    };

    int64 n;
    cin >> n;
    if (!n) {
        cout << 0 << "\n";
        return 0;
    }
    cout << (First * (Base ^ n)).val[0][0] << "\n";
}