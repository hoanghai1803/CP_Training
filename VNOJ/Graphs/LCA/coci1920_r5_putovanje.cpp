// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005
#define LOG_N 22

int n;
int depth[MAX_N];
vector<pair<int, int>> adj[MAX_N];
int par[LOG_N + 1][MAX_N];
int c[MAX_N], c2[MAX_N];
int edge[MAX_N], cnt[MAX_N], dp[MAX_N];


void dfs(int u, int p) {
    par[0][u] = p;
    for (int exp = 1; exp <= LOG_N; exp++)
        par[exp][u] = par[exp - 1][par[exp - 1][u]];

    for (auto [v, idx]: adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = LOG_N; k >= 0; k--)
        if (depth[par[k][u]] >= depth[v]) u = par[k][u];
    if (u == v) return u;
    for (int k = LOG_N; k >= 0; k--)
        if (par[k][u] != par[k][v]) u = par[k][u], v = par[k][v];
    return par[0][u];
}

void calc(int u, int p, int idx) {
    for (auto [v, new_idx]: adj[u]) {
        if (v == p) continue;
        calc(v, u, new_idx);
        dp[u] += dp[v];
    }
    dp[u] += cnt[u];
    edge[idx] = dp[u];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v >> c[i] >> c2[i];
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    dfs(1, 0);

    for (int u = 1; u < n; u++) {
        cnt[u]++, cnt[u + 1]++;
        cnt[lca(u, u + 1)] -= 2;
    }
    calc(1, 0, 0);

    long long ans = 0;
    for (int i = 1; i < n; i++)
        ans += min(1LL * c[i] * edge[i], 1LL * c2[i]);
    cout << ans;
}