// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define oo LLONG_MAX
#define MAX_N 111
#define MAX_W 100005

int N, W;
int w[MAX_N], v[MAX_N];
long long dp[MAX_N][MAX_W];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // Init
    cin >> N >> W;
    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) dp[i][j] = -oo;
    dp[1][0] = 0, dp[1][w[1]] = v[1];

    // DP
    for (int i = 2; i <= N; i++)
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
        }

    // Print out result
    long long res = -oo;
    for (int j = 0; j <= W; j++) res = max(res, dp[N][j]);
    cout << res << "\n";
}