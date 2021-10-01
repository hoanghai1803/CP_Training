// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define oo LLONG_MAX
#define MAX_N 111
#define MAX_V 100005

int N, W;
int w[MAX_N], v[MAX_N];
long long dp[MAX_V];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> N >> W;
    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

    for (int i = 0; i < MAX_V; i++) dp[i] = +oo;
    dp[0] = 0, dp[v[1]] = w[1];

    for (int k = 2; k <= N; k++)
        for (int i = MAX_V - 1; i >= 0; i--) 
            if (i - v[k] >= 0 && dp[i - v[k]] != +oo && dp[i - v[k]] + w[k] <= W)
                dp[i] = min(dp[i], dp[i - v[k]] + w[k]);

    for (int i = MAX_V - 1; i >= 0; i--)
        if (dp[i] != +oo) {
            cout << i << "\n";
            break;
        }
}