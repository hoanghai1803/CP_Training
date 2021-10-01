// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> iii;

#define oo INT_MAX
#define MAX_N 111
#define MAX_K 11111

int t, k, n, r;
vector<iii> adj[MAX_N];
int d[MAX_N][MAX_K];

void Dijkstra() {
    for (int u = 1; u <= n; u++)
        for (int t = 0; t <= k; t++) d[u][t] = +oo;
    d[1][k] = 0;

    priority_queue<iii, vector<iii>, greater<iii>> Heap;
    Heap.push({d[1][k], {1, k}});
    while (Heap.size()) {
        int du = Heap.top().first;
        int u = Heap.top().second.first, t = Heap.top().second.second;
        Heap.pop();

        if (du != d[u][t]) continue;
        if (u == n) {
            cout << d[u][t] << "\n";
            return;
        }

        for (iii e: adj[u]) {
            int v = e.first, l = e.second.first, w = e.second.second;
            if (t - w < 0) continue;
            if (d[v][t - w] > du + l) {
                d[v][t - w] = du + l;
                Heap.push({d[v][t - w], {v, t - w}});
            }
        }
    }
    
    cout << "-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> t; t--;) {
        cin >> k >> n >> r;
        for (int u = 1; u <= n; u++) adj[u].clear();

        for (int u, v, l, w; r--;) {
            cin >> u >> v >> l >> w;
            adj[u].push_back({v, {l, w}});
        }

        Dijkstra();
    }

}