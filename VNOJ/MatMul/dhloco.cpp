// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int64 n;
int M;

struct Matrix {
    int val[3][3];
    Matrix operator * (Matrix);
    Matrix operator ^ (int64);
} Base, First;

Matrix Matrix::operator * (Matrix other) {
    Matrix mul;
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++) {
            mul.val[r][c] = 0;
            for (int k = 0; k < 3; k++) 
                mul.val[r][c] += val[r][k] * other.val[k][c], mul.val[r][c] %= M;
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

    cin >> n >> M;
    Base = {0, 0, 1,
            1, 0, 1,
            0, 1, 1};
    First = {1, 2, 4};

    if (n == 1) cout << 1;
    if (n == 2) cout << 2;
    if (n == 3) cout << 4;
    if (n > 3) cout << (First * (Base ^ (n - 3))).val[0][2];
}