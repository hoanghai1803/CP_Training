// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 3003

int n, m;
vector<int> adj[MAX_N];
int dist[MAX_N], dp[MAX_N], cnt[MAX_N];

void bfs(int src) {
    memset(dist, -1, sizeof(dist));
    dist[src] = 0;

    queue<int> Q;
    Q.push(src);
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (int v : adj[u]) {
            if (dist[v] != -1) continue;
            cnt[dp[dist[v] = dist[u] + 1]]++;
            Q.push(v);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) dp[i] = max(dp[i / 2], dp[i / 2 + i % 2]) + 1;
    for (int u, v; m--;) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 1; u <= n; u++) bfs(u);
    for (int i = 1;; i++) {
        cout << cnt[i] / 2 << " ";
        if (!cnt[i]) break;
    }
}
