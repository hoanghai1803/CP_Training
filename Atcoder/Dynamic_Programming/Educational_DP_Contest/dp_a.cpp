// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

int n;
int h[MAX_N], dp[MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    dp[1] = 0, dp[2] = abs(h[2] - h[1]);
    for (int i = 3; i <= n; i++) 
        dp[i] = min(dp[i - 2] + abs(h[i] - h[i - 2]), dp[i - 1] + abs(h[i] - h[i - 1]));
    cout << dp[n] << "\n";
}