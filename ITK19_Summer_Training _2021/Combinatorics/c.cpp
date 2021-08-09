#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int pow(int a, int n) {
    if (n == 1)
        return a;
    int half = pow(a, n / 2);
    if (n & 1)
        return (1LL * half * half % MOD) * a % MOD;
    return 1LL * half * half % MOD;
}

int main() {
    int n, m;
    cin >> n >> m;
    int num = 1;
    for (int i = 1; i <= m + n - 1; i++)
        num = 1LL * num * i % MOD;
        
    int denom = 1;
    for (int i = 1; i <= n - 1; i++)
        denom = 1LL * denom * pow(i, MOD - 2) % MOD;
    for (int i = 1; i <= m; i++)
        denom = 1LL * denom * pow(i, MOD - 2) % MOD;

    cout << 1LL * num * denom % MOD;
}