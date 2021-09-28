// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x)*(x))

typedef long long int64;
typedef pair<double, int> dd;

#define oo FLT_MAX
#define MAX_N 1003

int n, w;
double m;
int64 x[MAX_N], y[MAX_N];
bool connected[MAX_N][MAX_N];
double d[MAX_N];
vector<dd> adj[MAX_N];

double Dist(int u, int v) {
    return (sqr(x[u] - x[v]) + sqr(y[u] - y[v]));
}

void Dijkstra() {
    d[1] = 0;
    for (int u = 2; u <= n; u++) d[u] = +oo;

    priority_queue<dd, vector<dd>, greater<dd>> Heap;
    Heap.push({d[1], 1});
    while (Heap.size()) {
        double du = Heap.top().first;
        int u = Heap.top().second;
        Heap.pop();
        if (du != d[u]) continue;
        if (u == n) break;
        for (auto vtx: adj[u]) {
            double w = vtx.first;
            int v = vtx.second;
            if (d[v] > du + w) {
                d[v] = du + w;
                Heap.push({d[v], v});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> w >> m;
    for (int u = 1; u <= n; u++) cin >> x[u] >> y[u];

    for (int u, v; w--;) {
        cin >> u >> v;
        adj[u].push_back({0, v});
        adj[v].push_back({0, u});
        connected[u][v] = true;
    }

    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++) {
            double d = Dist(u, v);
            if (u == v || connected[u][v] || d > m * m) continue;
            adj[u].push_back({sqrt(d), v});
            adj[v].push_back({sqrt(d), u});
        }

    Dijkstra();
    cout << (d[n] == +oo ? -1 : (int64)(d[n] * 1000)) << "\n";
}