// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

int n;
int h[MAX_N], dp[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> h[i];
	dp[1] = abs(h[1] - h[0]);
	for (int i = 2; i < n; i++)
		dp[i] = min(dp[i - 2] + abs(h[i] - h[i - 2]), dp[i - 1] + abs(h[i] - h[i - 1]));
	cout << dp[n - 1] << "\n";
}