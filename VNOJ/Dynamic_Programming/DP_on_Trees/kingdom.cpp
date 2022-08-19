// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 111
#define MAX_M 2004

int n, m;
int val[MAX_N], cost[MAX_N];
vector<int> adj[MAX_N];
int dp[MAX_N][MAX_M];

void dfs(int u, int par) {
    for (int w = cost[u]; w <= m; w++) {
        int c = w - cost[u];
        if (dp[par][w] == -1) continue;
        dp[u][c] = dp[par][w] + val[u];
    }

    for (int v: adj[u]) {
        if (v != par) dfs(v, u);
    }

    for (int w = 0; w <= m; w++)
        dp[par][w] = max(dp[par][w], dp[u][w]);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    for (int u = 2; u <= n; u++) 
        cin >> val[u];
    for (int u = 2; u <= n; u++)
        cin >> cost[u];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp, -1, sizeof(dp));
    dp[0][m] = 0;
    dfs(1, 0);
    cout << *max_element(dp[1], dp[1] + 1 + m) << "\n";
}