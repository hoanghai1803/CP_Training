// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int64;

#define MAX_N 100
#define MOD (1LL << 32)

struct Matrix {
    int64 val[MAX_N][MAX_N];
    Matrix operator * (Matrix);
    Matrix operator ^ (int);
};

Matrix Matrix::operator * (Matrix other) {
    Matrix mul;
    for (int r = 0; r < MAX_N; r++)
        for (int c = 0; c < MAX_N; c++) {
            mul.val[r][c] = 0;
            for (int k = 0; k < MAX_N; k++) {
                mul.val[r][c] += val[r][k] * other.val[k][c] % MOD;
                mul.val[r][c] %= MOD;
            }
        }
    return mul;
}

Matrix Matrix::operator ^ (int exp) {
    if (exp == 1) return *this;
    Matrix half = (*this) ^ (exp / 2);
    if (exp & 1) return half * half * (*this);
    return half * half;
}

bool isValid(int r, int c) {
    return r > 0 && r <= 8 && c > 0 && c <= 8;
}

int toNum(int r, int c) {
    return (r - 1) * 8 + c;
}

Matrix First, Base;

void addEdge(int r, int c, int __r, int __c) {
    if (!isValid(r, c) || !isValid(__r, __c)) return;
    int u = toNum(r, c), v = toNum(__r, __c);
    Base.val[u][v] = Base.val[v][u] = 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    First.val[0][1] = 1;
    for (int u = 1; u <= 8 * 8 + 1; u++) Base.val[u][8 * 8 + 1] = 1;

    for (int r = 1; r <= 8; r++)
        for (int c = 1; c <= 8; c++) {
            for (int __r = r - 2; __r <= r + 2; __r++) {
                if (__r == r) continue;
                addEdge(r, c, __r, c + (3 - abs(r - __r)));
                addEdge(r, c, __r, c - (3 - abs(r - __r)));
            }
        }

    int k;
    cin >> k;
    cout << (First * (Base ^ (k + 1))).val[0][8 * 8 + 1] << "\n";
}