// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

#define oo INT_MAX
#define MAX_N 30004

int n, m;
int d[2][MAX_N];
int64 cnt[2][MAX_N];
vector<ii> adj[MAX_N];

void Dijkstra(int id, int src) {
    for (int u = 1; u <= n; u++) d[id][u] = +oo;
    d[id][src] = 0, cnt[id][src] = 1;

    priority_queue<ii, vector<ii>, greater<ii>> Heap;
    Heap.push({d[id][src], src});
    while (Heap.size()) {
        int du = Heap.top().first, u = Heap.top().second;
        Heap.pop();
        if (du != d[id][u]) continue;
        for (ii vtx: adj[u]) {
            int v = vtx.first, w = vtx.second;
            if (d[id][v] == du + w) {
                cnt[id][v] += cnt[id][u];
                continue;
            }
            if (d[id][v] > du + w) {
                d[id][v] = du + w;
                cnt[id][v] = cnt[id][u];
                Heap.push({d[id][v], v});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> n >> m;
    for (int u, v, w; m--;) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    Dijkstra(0, 1);
    Dijkstra(1, n);

    vector<int> cities;
    for (int u = 2; u < n; u++)
        if (d[0][u] + d[1][u] != d[0][n] || cnt[0][u] * cnt[1][u] != cnt[0][n]) cities.push_back(u);
    cout << cities.size() << "\n";
    for (int u: cities) cout << u << "\n";
}