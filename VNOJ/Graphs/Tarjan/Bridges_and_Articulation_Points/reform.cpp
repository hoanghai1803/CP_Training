// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005

int n, m, ncc, firstCC;
vector<int> adj[MAX_N];
int cnt, bridges;
int dfn[MAX_N], low[MAX_N], S[MAX_N];

void dfs(int u, int par) {
    dfn[u] = low[u] = ++cnt, S[u] = 1;
    for (int v: adj[u]) {
        if (v == par) continue;
        if (dfn[v]) {
            low[u] = min(low[u], dfn[v]);
            continue;
        } 
        dfs(v, u);
        S[u] += S[v];
        low[u] = min(low[u], low[v]);
    }
    bridges += (low[u] == dfn[u] && par);
}


int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 1; u <= n; u++) {
        if (dfn[u]) continue;
        ncc++;
        dfs(u, 0);
        if (u == 1) firstCC = cnt;
    }

    if (ncc == 1) {
        long long res = (1LL * n * (n - 1) / 2 - m) * (m - bridges);
        for (int u = 1; u <= n; u++) {
            if (low[u] == dfn[u] && dfn[u] != 1) 
                res += 1LL * S[u] * (n - S[u]) - 1;
        }
        cout << res << "\n";
    } else if (ncc == 2) {
        cout << 1LL * firstCC * (n - firstCC) * (m - bridges) << "\n";
    } else cout << 0 << "\n";
}