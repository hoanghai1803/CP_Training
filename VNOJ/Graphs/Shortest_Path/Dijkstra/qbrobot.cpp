// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define oo (int)1e8
#define MAX_N 555

struct Edge {
    int vtx, t, c;
};

int n, m;
bool refill[MAX_N];
vector<Edge> adj[MAX_N];
int d[MAX_N], fuel[MAX_N];

int Dijkstra(int w) {
    d[1] = 0, fuel[1] = w;
    for (int u = 2; u <= n; u++) d[u] = +oo, fuel[u] = 0;

    priority_queue<ii, vector<ii>, greater<ii>> Heap;
    Heap.push({d[1], 1});
    while (Heap.size()) {
        int du = Heap.top().first, u = Heap.top().second;
        Heap.pop();
        if (du != d[u]) continue;
        if (u == n) break;
        for (auto e: adj[u]) {
            int v = e.vtx, t = e.t, c = e.c;
            if (fuel[u] < c) continue;

            if (d[v] == du + t) 
                fuel[v] = refill[v] ? w : max(fuel[v], fuel[u] - c);

            if (d[v] > du + t) {
                d[v] = du + t;
                fuel[v] = refill[v] ? w : fuel[u] - c;
                Heap.push({d[v], v});
            }
        }
    }

    return d[n];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int u = 1; u <= n; u++) cin >> refill[u];
    for (cin >> m; m--;) {
        int u, v, t, c;
        cin >> u >> v >> t >> c;
        adj[u].push_back({v, t, c});
        adj[v].push_back({u, t, c});
    }

    int minRoad = Dijkstra(+oo);
    for (int L = 1, R = +oo; ;) {
        int M = (L + R) >> 1;
        if (M == L || M == R) {
            if (Dijkstra(L) == minRoad) cout << L << "\n";
            else cout << R << "\n";
            break;
        }
        if (Dijkstra(M) == minRoad) R = M;
        else L = M;
    }
}