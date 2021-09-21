// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int n, dp[3], a, b, c;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		int dp_0 = max(dp[1] + a, dp[2] + a);
		int dp_1 = max(dp[0] + b, dp[2] + b);
		int dp_2 = max(dp[0] + c, dp[1] + c);
		dp[0] = dp_0, dp[1] = dp_1, dp[2] = dp_2;
	}
	cout << max(dp[0], max(dp[1], dp[2]));
}