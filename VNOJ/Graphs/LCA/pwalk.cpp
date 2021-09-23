// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1111
#define LOG_N 11

int n, q;
vector<pair<int, int>> adj[MAX_N];
int depth[MAX_N], dist[MAX_N];
int Par[LOG_N + 1][MAX_N];

void dfs(int u) {
    for (auto child: adj[u]) {
        int v = child.first, l = child.second;
        if (v == Par[0][u]) continue;
        depth[v] = depth[u] + 1;
        dist[v] = dist[u] + l;
        Par[0][v] = u;
        dfs(v);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = LOG_N; k >= 0; k--)
        if (depth[Par[k][u]] >= depth[v]) u = Par[k][u];
    if (u == v) return u;
    for (int k = LOG_N; k >= 0; k--)
        if (Par[k][u] != Par[k][v]) u = Par[k][u], v = Par[k][v];
    return Par[0][u];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }

    depth[1] = 1, dist[1] = 0;
    dfs(1);

    for (int k = 1; k <= LOG_N; k++) 
        for (int u = 1; u <= n; u++) 
            Par[k][u] = Par[k - 1][Par[k - 1][u]];

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << dist[u] + dist[v] - 2 * dist[lca(u, v)] << "\n";
    }
}