// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 1000006
const int MOD = 1e9 + 7;
 
int n;
int dp[MAX_N];
 
int main() {
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		int max_j = min(i, 6);
		for (int j = 1; j <= max_j; j++) dp[i] = (dp[i] + dp[i - j]) % MOD;
	}
	cout << dp[n];	
}