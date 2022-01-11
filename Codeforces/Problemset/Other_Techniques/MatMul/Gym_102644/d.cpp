// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 111
#define MOD (int)(1e9 + 7)

struct Matrix {
    int val[MAX_N][MAX_N];
    Matrix operator * (Matrix);
    Matrix operator ^ (int);
};

Matrix Matrix::operator * (Matrix other) {
    Matrix mul;
    for (int r = 0; r < MAX_N; r++)
        for (int c = 0; c < MAX_N; c++) {
            mul.val[r][c] = 0;
            for (int k = 0; k < MAX_N; k++) {
                mul.val[r][c] += 1LL * val[r][k] * other.val[k][c] % MOD;
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

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> deg_out(n + 1);
    Matrix First, Base;

    for (int u, v; m--;) {
        cin >> u >> v;
        deg_out[u]++;
        Base.val[v][u] = 1;
    }
    for (int u = 1; u <= n; u++) First.val[0][u] = (deg_out[u] > 0);

    Matrix temp = First * (Base ^ k);
    int res = 0;
    for (int u = 1; u <= n; u++) res = (res + temp.val[0][u]) % MOD;
    cout << res << "\n";
}