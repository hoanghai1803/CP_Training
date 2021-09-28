// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define oo INT_MAX
#define MAX_N 33333

void Dijkstra(vector<ii> adj[], int n) {
    vector<int> d(n + 1);
    d[0] = 0;
    for (int u = 1; u <= n; u++) d[u] = +oo;

    priority_queue<ii, vector<ii>, greater<ii>> Heap;
    Heap.push({d[0], 0});

    while (Heap.size()) {
        int du = Heap.top().first, u = Heap.top().second;
        Heap.pop();
        if (du != d[u]) continue;
        if (u == n) break;
        for (ii vtx: adj[u]) {
            int v = vtx.first, w = vtx.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Heap.push({d[v], v});
            }
        }
    }

    cout << d[n] << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int m, n;
    vector<ii> adj[MAX_N];
    cin >> m >> n;

    int w;
    for (int u = 1; u <= n; u++) {
        cin >> w;
        adj[0].push_back({u, w});
    }
    for (int u = 1; u < 2 * m; u++) {
        for (int v = 1; v <= n - (u & 1); v++) {
            cin >> w;
            int vtx = (u - 2 + (u & 1)) / 2 * n + v;
            if (u & 1) {
                adj[vtx].push_back({vtx + 1, w});
                adj[vtx + 1].push_back({vtx, w});
            } else {
                adj[vtx].push_back({vtx + n, w});
                adj[vtx + n].push_back({vtx, w});
            }
        }
    }
    
    Dijkstra(adj, m * n);
}