// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_CHAR ('z' - 'a' + 1)
#define MAX_N 5003
#define MOD 998244353

string str;
int cnt[MAX_CHAR + 1];
int fact[MAX_N], iFact[MAX_N];
int dp[MAX_CHAR + 1][MAX_N];

int Pow(int a, int n) {
    if (!n) return 1;
    int half = Pow(a, n / 2);
    if (n & 1) return (1LL * half * half % MOD) * a % MOD;
    return 1LL * half * half % MOD;
}

int binom(int n, int k) {
    return (1LL * fact[n] * iFact[k] % MOD) * iFact[n - k] % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // Pre-compute factorial and inverse factorial
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) fact[i] = 1LL * fact[i - 1] * i % MOD;
    iFact[MAX_N - 1] = Pow(fact[MAX_N - 1], MOD - 2);
    for (int i = MAX_N - 1; i >= 1; i--) iFact[i - 1] = 1LL * iFact[i] * i % MOD;

    cin >> str;
    for (int i = 0; i < (int)str.size(); i++)
        cnt[str[i] - 'a' + 1]++;

    dp[0][0] = 1;
    for (int ch = 1; ch <= MAX_CHAR; ch++) {
        for (int i = 0; i <= cnt[ch - 1]; i++)
            for (int j = 0; j <= cnt[ch]; j++) {
                dp[ch][i + j] = (dp[ch][i + j] + 1LL * dp[ch - 1][i] * binom(i + j, i) % MOD) % MOD;
            }
        cnt[ch] += cnt[ch - 1];
    }
    
    int res = 0;
    for (int i = 1; i <= (int)str.size(); i++)
        res = (res + dp[MAX_CHAR][i]) % MOD;
    cout << res << "\n";
}