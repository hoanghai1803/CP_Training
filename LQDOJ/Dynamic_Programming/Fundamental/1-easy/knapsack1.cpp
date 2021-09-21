// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 111
#define MAX_W 100005
#define oo LLONG_MAX

int N, W;
int w[MAX_N], v[MAX_N];
long long dp[MAX_N][MAX_W];

int main() {
    cin.tie(0)->sync_with_stdio(false);

	// Input data
    cin >> N >> W;
	for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

	// DP base
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) dp[i][j] = -oo;
	dp[0][0] = 0, dp[0][w[0]] = v[0];

	// DP sol
	for (int i = 1; i < N; i++)
		for (int j = 0; j <= W; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - w[i] >= 0)
			dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
		}

	// Print out result
	long long res = -oo;
	for (int j = 0; j <= W; j++) res = max(res, dp[N - 1][j]);
	cout << res << "\n";
}