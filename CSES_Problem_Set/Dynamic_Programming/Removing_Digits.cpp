// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 1000006
 
int n;
int dp[MAX_N];
 
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1e9;
		for (char ch: to_string(i)) 
			dp[i] = min(dp[i], dp[i - (ch - '0')] + 1);
	}
	cout << dp[n];
}	