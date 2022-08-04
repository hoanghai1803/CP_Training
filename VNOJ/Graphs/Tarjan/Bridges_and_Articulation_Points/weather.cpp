// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 111

int n, m, timer;
vector<int> adj[MAX_N];
int S[MAX_N], num[MAX_N], low[MAX_N];

void dfs(int u, int p) {
    num[u] = low[u] = ++timer;
    S[u] = 1;
    for (int v: adj[u]) {
        if (v == p) continue;
        if (num[v]) {
            low[u] = min(low[u], num[v]);
            continue;
        }
        dfs(v, u);
        S[u] += S[v];
        low[u] = min(low[u], low[v]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    int ans = 0;
    for (int u = 2; u <= n; u++) {
        if (low[u] == num[u]) ans += S[u] * (n - S[u]);
    }
    cout << ans << "\n";
}