// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
#define MAX_N 102
#define MAX_SUM 1000006
 
int n, x;
int c[MAX_N];
int dp[MAX_N][MAX_SUM];
 
int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) 
		cin >> c[i];
 
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) 
		for (int sum = 0; sum <= x; sum++) 
		 	dp[i][sum] = (dp[i - 1][sum] + (sum - c[i] >= 0 ? dp[i][sum - c[i]] : 0)) % MOD;
	
	cout << dp[n][x];
}