// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5e4 + 4;
const int MOD = 1e9 + 9;
const int BASE = 10;

int t, n;
string k;
int fact[2 * MAX_N], inv_fact[2 * MAX_N];
int C[MAX_N];

int Pow(int a, int n) {
    if (!n) return 1;
    int half = Pow(a, n / 2);
    if (n & 1) 
        return (1LL * half * half % MOD) * a % MOD;
    return 1LL * half * half % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // Pre-Computing
    C[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        int num = (1LL * C[i - 1] * (2 * i - 1) % MOD) * 2 * i % MOD;
        int denom = 1LL * Pow(i, MOD - 2) * Pow(i + 1, MOD - 2) % MOD;
        C[i] = 1LL * num * denom % MOD;
    }

    // Queries
    for (cin >> t; t--;) {
        cin >> n >> k;
        int hashK = 0;
        for (int i = 0; i < (int)k.length(); i++)
            hashK = (1LL * hashK * BASE + k[i] - '0') % MOD;
        cout << (C[n] == hashK ? "YES\n" : "NO\n");
    }
}
