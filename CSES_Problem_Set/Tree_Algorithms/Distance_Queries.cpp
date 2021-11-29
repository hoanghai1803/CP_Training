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

int dist(int u, int v) {
    int ret = 0;
    if (depth[u] < depth[v]) swap(u, v);

    for (int k = LOG_N; k >= 0; k--)
        if (depth[par[k][u]] >= depth[v]) {
            u = par[k][u]; 
            ret += 1 << k;
        }
    if (u == v) return ret;

    for (int k = LOG_N; k >= 0; k--)
        if (par[k][u] != par[k][v]) {
            u = par[k][u], v = par[k][v];
            ret += 1 << (k + 1);
        }
    return ret + 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 1;
    dfs(1);

    for (int k = 1; k <= LOG_N; k++) 
        for (int u = 1; u <= n; u++) 
            par[k][u] = par[k - 1][par[k - 1][u]];

    for (int u, v; q--;) {
        cin >> u >> v;
        cout << dist(u, v) << "\n";
    }
}