// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 77777
#define LOG_N 22

int n, q;
vector<int> adj[MAX_N];
int depth[MAX_N], Par[LOG_N + 1][MAX_N];
int M[LOG_N + 1][MAX_N];

void dfs(int u) {
    for (int v: adj[u]) {
        if (v == Par[0][u]) continue;
        depth[v] = depth[u] + 1;
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
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 1;
    dfs(1);

    for (int k = 1; k <= LOG_N; k++) 
        for (int u = 1; u <= n; u++) 
            Par[k][u] = Par[k - 1][Par[k - 1][u]];

    // Sparse Table
    for (int u = 1; u <= n; u++) M[0][u] = u;
    for (int k = 1; k <= LOG_N; k++)
        for (int u = 1; u + (1 << k) - 1 <= n; u++)
            M[k][u] = lca(M[k - 1][u], M[k - 1][u + (1 << (k - 1))]);

    while (q--) {
        int u, v;
        cin >> u >> v;
        int k = log2(v - u + 1);
        cout << lca(M[k][u], M[k][v - (1 << k) + 1]) << "\n";
    }
}