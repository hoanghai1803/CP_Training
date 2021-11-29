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

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q;
    for (int u = 2, boss; u <= n; u++) {
        cin >> boss;
        adj[boss].push_back(u);
    }

    dfs(1);
    for (int k = 1; k <= LOG_N; k++)
        for (int u = 1; u <= n; u++)
            par[k][u] = par[k - 1][par[k - 1][u]];

    for (int u, k; q--;) {
        cin >> u >> k;
        for (int i = LOG_N; i >= 0; i--) 
            if ((1 << i) <= k) u = par[i][u], k -= (1 << i);
        cout << (u ? u : -1) << "\n";
    }
}