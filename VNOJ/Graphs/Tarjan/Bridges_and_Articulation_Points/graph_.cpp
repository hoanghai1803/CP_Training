// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

int n, m, timer;
int num[MAX_N], low[MAX_N], cnt[MAX_N];
vector<int> adj[MAX_N];
int AP, bridges;

void dfs(int u, int par) {
    num[u] = low[u] = ++timer;
    for (int v: adj[u]) {
        if (v == par) continue;
        if (num[v]) {
            low[u] = min(low[u], num[v]);
            continue;
        }
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        cnt[u] += low[v] >= num[u];
    }
    AP += par ? (cnt[u] >= 1) : (cnt[u] >= 2);
    bridges += (par && low[u] == num[u]);
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

    for (int u = 1; u <= n; u++)
        if (!num[u]) dfs(u, 0);
    cout << AP << " " << bridges << "\n";
}