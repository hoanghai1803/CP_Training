#include <bits/stdc++.h>
 
using namespace std;
 
const int oo = 1e9;
#define MAX_N 102
#define MAX_SUM 1000006
 
int n, x;
int c[MAX_N];
int dp[MAX_SUM];
 
int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) 
		cin >> c[i];
	
	for (int sum = 1; sum <= x; sum++) {
		dp[sum] = +oo;
		for (int i = 0; i < n; i++) 
			if (sum - c[i] >= 0) dp[sum] =  min(dp[sum], dp[sum - c[i]] + 1);
	}
 
	cout << (dp[x] == +oo ? -1 : dp[x]);
}