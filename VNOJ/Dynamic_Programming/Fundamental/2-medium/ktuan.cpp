// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;
const int MOD = 1e9;

int n;
int dp[MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        int sign = 1;
        for (int j = 1; ; j++) {
            int k = j * (3 * j - 1) / 2;
            if (k > i) break;
            dp[i] = (dp[i] + sign * dp[i - k]) % MOD;
            if (dp[i] < 0) dp[i] += MOD;
            k += j;
            if (k > i) break;
            dp[i] = (dp[i] + sign * dp[i - k]) % MOD;
            if (dp[i] < 0) dp[i] += MOD;
            sign *= -1;
        }
    }
    cout << (n ? dp[n] : 0) << "\n";
}