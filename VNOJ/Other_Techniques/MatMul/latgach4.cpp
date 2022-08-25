// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MOD 111539786

struct Matrix {
    int64 val[2][2];
    Matrix operator * (Matrix);
    Matrix operator ^ (int64);
} Base, First;

Matrix Matrix::operator * (Matrix other) {
    Matrix mul;
    for (int r = 0; r < 2; r++)
        for (int c = 0; c < 2; c++) {
            mul.val[r][c] = 0;
            for (int k = 0; k < 2; k++) 
                mul.val[r][c] += val[r][k] * other.val[k][c], mul.val[r][c] %= MOD;
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

    int64 t, n;
    for (cin >> t; t--;) {
        cin >> n;
        if (n == 1) cout << "1\n";
        else cout << (First * (Base ^ (n - 1))).val[0][1] << "\n";
    }
}