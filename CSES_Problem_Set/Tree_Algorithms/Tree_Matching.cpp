// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005

int n;
vector<int> adj[MAX_N];
int dp[2][MAX_N];

void dfs(int u, int par) {
    for (int v: adj[u]) {
        if (v == par) continue;
        dfs(v, u);
        dp[0][u] += max(dp[0][v], dp[1][v]);
    }

    for (int v: adj[u]) {
        if (v == par) continue;
        dp[1][u] = max(dp[1][u], 1 + dp[0][u] + dp[0][v] - max(dp[0][v], dp[1][v]));
    }
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

    dfs(1, 0);
    cout << max(dp[0][1], dp[1][1]) << "\n";
}