// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005
#define LOG_N 22

int n, q;
vector<int> adj[MAX_N];
int depth[MAX_N], par[LOG_N + 1][MAX_N];

void dfs(int u) {
    for (int v: adj[u]) {
        if (v == par[0][u]) continue;
        depth[v] = depth[u] + 1;
        par[0][v] = u;
        dfs(v);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = LOG_N; k >= 0; k--)
        if (depth[par[k][u]] >= depth[v]) u = par[k][u];
    if (u == v) return u;
    for (int k = LOG_N; k >= 0; k--) 
        if (par[k][u] != par[k][v])
            u = par[k][u], v = par[k][v];
    return par[0][u];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q;
    for (int u = 2, boss; u <= n; u++) {
        cin >> boss;
        adj[boss].push_back(u);
    }

    depth[1] = 1;
    dfs(1);
    for (int k = 1; k <= LOG_N; k++)
        for (int u = 1; u <= n; u++)
            par[k][u] = par[k - 1][par[k - 1][u]];

    for (int u, v; q--;) {
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}