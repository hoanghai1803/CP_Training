#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
#define MAX_N 102
#define MAX_SUM 1000006
 
int n, x;
int c[MAX_N];
int dp[MAX_SUM];
 
int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) 
		cin >> c[i];
 
	dp[0] = 1;
	for (int sum = 1; sum <= x; sum++) 
		for (int i = 0; i < n; i++) 
			if (sum - c[i] >= 0) dp[sum] = (dp[sum] + dp[sum - c[i]]) % MOD;
	
	cout << dp[x];
}