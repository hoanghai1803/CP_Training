// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MOD (int)(1e9+7)
#define MAX_N 100005

int n;
vector<int> adj[MAX_N];
int dp[MAX_N][2]; // 0 for black, 1 for white

int calc(int u, bool c, int par) {
    if (dp[u][c] != -1) return dp[u][c];
    
    dp[u][c] = 1;
    for (int v: adj[u]) {
        if (v == par) continue;
        int sum = c ? calc(v, 0, u) : 0;
        sum = (sum + calc(v, 1, u)) % MOD;
        dp[u][c] = 1LL * dp[u][c] * sum % MOD;
    }
    return dp[u][c];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp, -1, sizeof(dp));
    cout << (calc(1, 0, -1) + calc(1, 1, -1)) % MOD << "\n";
}