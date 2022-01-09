// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

struct Matrix {
    ld val[2][2];
    Matrix operator * (Matrix);
    Matrix operator ^ (int);
};

Matrix Matrix::operator * (Matrix other) {
    Matrix mul;
    for (int r = 0; r < 2; r++)
        for (int c = 0; c < 2; c++) {
            mul.val[r][c] = 0;
            for (int k = 0; k < 2; k++) 
                mul.val[r][c] += val[r][k] * other.val[k][c];
        }
    return mul;
}

Matrix Matrix::operator ^ (int exp) {
    if (exp == 1) return *this;
    Matrix half = (*this) ^ (exp / 2);
    if (exp & 1) return half * half * (*this);
    return half * half;
}


int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    double p;
    cin >> n >> p;
    Matrix First = {
        0, 1,
        0, 0
    };
    Matrix Base = {
        1 - p, p,
        p, 1 - p
    };
    cout << fixed << setprecision(10) << (First * (Base ^ n)).val[0][1] << "\n";
}