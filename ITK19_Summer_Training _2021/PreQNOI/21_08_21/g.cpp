#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005

int n, x;
vector<int> adj[MAX_N];
int dist[2][MAX_N];

void dfs(bool id, int u) {
    for (int v: adj[u]) {
        if (dist[id][v])
            continue;
        dist[id][v] = dist[id][u] + 1;
        dfs(id, v);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> x;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dist[0][1] = dist[1][x] = 1;
    dfs(0, 1);
    dfs(1, x);

    int res = 0;
    for (int u = 2; u <= n; u++) 
        if (dist[1][u] < dist[0][u])
            res = max(res, (dist[0][u] - 1) * 2);
    cout << res << "\n";
}