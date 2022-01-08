// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

int n, m;
int deg_in[MAX_N], dist[MAX_N];
vector<int> adj[MAX_N];
queue<int> Q;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    for (int u, v; m--;) {
        cin >> u >> v;
        adj[u].push_back(v);
        deg_in[v]++;
    }

    for (int u = 1; u <= n; u++) 
        if (!deg_in[u]) Q.push(u);

    int res = 0;
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        res = max(res, dist[u]);
        for (int v: adj[u]) {
            dist[v] = max(dist[v], dist[u] + 1);
            if (!--deg_in[v]) Q.push(v);
        }
    }
    cout << res << "\n";
}