// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10004

int n, m, s;
set<int> adj[MAX_N];
int dist[MAX_N], cnt[MAX_N];

void bfs(int src) {
    memset(dist, -1, sizeof(dist));
    dist[src] = 0, cnt[src] = 1;

    queue<int> Q;
    Q.push(src);

    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (int v: adj[u]) {
            if (dist[v] != -1) {
                if (dist[u] + 1 == dist[v]) {
                    if (cnt[v] == 1) cnt[v] = 2;
                }
            } else {
                dist[v] = dist[u] + 1, cnt[v] = cnt[u];
                Q.push(v);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m >> s;
    for (int u, v; m--;) {
        cin >> u >> v;
        adj[u].insert(v);
    }

    bfs(s);
    int res = 0;
    for (int u = 1; u <= n; u++)
        res += (cnt[u] == 2);
    cout << res << "\n";
}