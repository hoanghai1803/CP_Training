#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005
#define LOG_N 22

int n, m;
vector<int> adj[MAX_N];
int depth[MAX_N], cnt[MAX_N], par[LOG_N + 1][MAX_N];

void dfs(int u) {
    for (int v: adj[u]) {
        if (v == par[0][u]) continue;
        depth[v] = depth[u] + 1;
        par[0][v] = u;
        dfs(v);
    }
}

void updatePath(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int k = LOG_N; k >= 0; k--) 
        if (depth[par[k][u]] >= depth[v]) {
            cnt[u]++, cnt[par[k][u]]--;
            u = par[k][u];
        }
    if (u == v) {
        cnt[u]++, cnt[par[0][u]]--;
        return;
    }


    for (int k = LOG_N; k >= 0; k--)
        if (par[k][u] != par[k][v]) {
            cnt[u]++, cnt[par[k][u]]--;
            u = par[k][u];
            cnt[v]++, cnt[par[k][v]]--;
            v = par[k][v];
        }
    cnt[u]++, cnt[v]++;
    cnt[par[0][u]]--;
    cnt[par[1][u]]--;
}

void countingPath(int u) {
    for (int v: adj[u]) {
        if (v == par[0][u]) continue;
        countingPath(v);
        cnt[u] += cnt[v];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
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

    for (int u, v; m--;) {
        cin >> u >> v;
        updatePath(u, v);
    }

    countingPath(1);
    for (int u = 1; u <= n; u++)
        cout << cnt[u] << " ";
    cout << "\n";
}