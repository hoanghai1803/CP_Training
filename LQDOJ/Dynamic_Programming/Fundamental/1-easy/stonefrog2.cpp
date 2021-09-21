// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define oo INT_MAX

int n, k;
int h[MAX_N];
int dp[MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);
	
    cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 1; i < n; i++) {
		dp[i] = +oo;
		for (int j = max(i - k, 0); j < i; j++) 
			dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j])); 
	}
    cout << dp[n - 1] << "\n";
}