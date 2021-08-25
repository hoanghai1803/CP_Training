// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
#define MAX_N 100005
#define MAX_M 102
 
int n, m, x;
int dp[MAX_N][MAX_M];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x) {
			dp[i][x] = (i == 1) ? 1 : ((dp[i - 1][x - 1] + dp[i - 1][x]) % MOD + dp[i - 1][x + 1]) % MOD;
			continue;
		}
		for (int x = 1; x <= m; x++) 
			dp[i][x] = (i == 1) ? 1 : ((dp[i - 1][x - 1] + dp[i - 1][x]) % MOD + dp[i - 1][x + 1]) % MOD;
	}
 
	int res = 0;
	for (int x = 1; x <= m; x++) res = (res + dp[n][x]) % MOD;
	cout << res;	
}