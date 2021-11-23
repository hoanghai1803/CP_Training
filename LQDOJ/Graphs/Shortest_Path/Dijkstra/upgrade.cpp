// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

#define oo (int64)(1e15)
#define MAX_N 100005

int n, m;
int64 d[2][MAX_N], cnt[2][MAX_N];
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
        for (ii edge: adj[u]) {
            int v = edge.first, t = edge.second;
            if (d[id][v] == du + t) {
                cnt[id][v] += cnt[id][u];
                continue;
            }
            if (d[id][v] > du + t) {
                d[id][v] = du + t;
                cnt[id][v] = cnt[id][u];
                Heap.push({d[id][v], v});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    while (m--) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    Dijkstra(0, 1);
    Dijkstra(1, n);

    int res = 0;
    for (int u = 1; u <= n; u++) 
        for (ii edge: adj[u]) {
            int v = edge.first, t = edge.second;
            if (d[0][u] + d[1][v] + t == d[0][n] && cnt[0][u] * cnt[1][v] == cnt[0][n])
                res++;
        }

    cout << res << "\n";
}