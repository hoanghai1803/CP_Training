// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MOD 14062008

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k, x;
    cin >> n >> k;
    vector<bool> a(n, true);
    while (k--) {
        cin >> x;
        a[x - 1] = false;
    }

    vector<int> dp(n);
    dp[0] = 1, dp[1] = a[1];
    for (int i = 1; i < n; i++)
        dp[i] = a[i] * (dp[i - 1] + dp[i - 2]) % MOD;
    cout << dp[n - 1];
}
