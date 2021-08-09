#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
#define MAX_N 1003
 
int n;
int dp[MAX_N][MAX_N];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			char square;
			cin >> square;
			if (i == 1 && j == 1) {
				dp[i][j] = square == '.';
				continue;
			} 
			dp[i][j] = square == '.' ? (dp[i - 1][j] + dp[i][j - 1]) % MOD : 0;		
		}
	cout << dp[n][n];
}