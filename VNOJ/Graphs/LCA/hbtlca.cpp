// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define LOG_N 22

int t, n, q;
vector<int> adj[MAX_N];
int depth[MAX_N];
int Par[LOG_N + 1][MAX_N];

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

    while (true) {
        cin >> n;
        if (!n) break;
        for (int u = 1; u <= n; u++) adj[u].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        depth[1] = 1, Par[0][1] = 0;
        dfs(1); 

        for (int k = 1; k <= LOG_N; k++) 
            for (int u = 1; u <= n; u++) 
                Par[k][u] = Par[k - 1][Par[k - 1][u]];


        int root = 1;
        char ch;
        int u, v;
        for (cin >> q; q--;) {
            cin >> ch;
            if (ch == '!') {
                cin >> root;
                continue;
            }

            cin >> u >> v;
            if (depth[lca(u, root)] < depth[lca(v, root)]) swap(u, v);
            cout << (depth[lca(u, root)] > depth[lca(u, v)] ? lca(u, root) : lca(u, v)) << "\n";
        }
    }
}