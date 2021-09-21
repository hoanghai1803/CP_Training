// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 111
#define MAX_V 100005
#define oo LLONG_MAX

int N, W;
int w[MAX_N], v[MAX_N];
long long dp[MAX_V];

int main() {
    cin.tie(0)->sync_with_stdio(false);

	// Input data
    cin >> N >> W;
	for (int i = 0; i < N; i++)
        cin >> w[i] >> v[i];

	// DP base
	for (int _v = 0; _v < MAX_V; _v++)
		dp[_v] = +oo;
	dp[0] = 0, dp[v[0]] = w[0];

	// DP sol
	for (int i = 1; i < N; i++) 
		for (int _v = MAX_V - 1; _v >= 0; _v--) 
			if (_v - v[i] >= 0 && dp[_v - v[i]] != +oo && dp[_v - v[i]] + w[i] <= W) 
				dp[_v] = min(dp[_v], dp[_v - v[i]] + w[i]);

	// Print result
	for (int _v = MAX_V - 1; _v >= 0; _v--)
		if (dp[_v] != +oo) {
            cout << _v << "\n";
			return 0;
		}
}