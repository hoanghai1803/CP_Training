#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353
#define MAX_N 200005

int n, m;
int fact[MAX_N], powFact[MAX_N];

int pow(int a, int n) {
    if (!n)
        return 1;
    int half = pow(a, n / 2);
    if (n & 1)
        return (1LL * half * half % MOD) * a % MOD;
    return 1LL * half * half % MOD;
}

int main() {
    cin >> n >> m;
    if (n == 2) {
        cout << 0;
        return 0;
    }

    fact[0] = 1;
    for (int i = 1; i <= m; i++)
        fact[i] = 1LL * fact[i - 1] * i % MOD;
    powFact[0] = 1;
    for (int i = 1; i <= m; i++)
        powFact[i] = 1LL * powFact[i - 1] * pow(i, MOD - 2) % MOD;
    
    int Comb = (1LL * fact[m] * powFact[n - 1] % MOD) * powFact[m - n + 1] % MOD;
    cout << (1LL * Comb * (n - 2) % MOD) * pow(2, n - 3) % MOD;
}