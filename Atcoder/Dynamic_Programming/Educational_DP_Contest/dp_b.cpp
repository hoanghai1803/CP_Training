// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define MAX_N 100005

int n, k;
int h[MAX_N], dp[MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 2; i <= n; i++) {
        dp[i] = +oo;
        for (int j = max(i - k, 1); j < i; j++) 
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
    }
    cout << dp[n]  << "\n";
}