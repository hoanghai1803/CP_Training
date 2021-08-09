#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 1003
#define MAX_COST 100005
 
int n, x;
int h[MAX_N], s[MAX_N];
int dp[MAX_N][MAX_COST];
 
int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> s[i];
 
	for (int i = 1; i <= n; i++) 
		for (int cost = 1; cost <= x; cost++) {
			dp[i][cost] = dp[i - 1][cost];
			if (cost - h[i] >= 0) dp[i][cost] = max(dp[i][cost], dp[i - 1][cost - h[i]] + s[i]);
		}
 
	cout << dp[n][x];
}