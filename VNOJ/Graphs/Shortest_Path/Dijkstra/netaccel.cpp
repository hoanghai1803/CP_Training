// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, double> pid;
typedef pair<double, pii> pdii;

#define MAX_N 1003
#define MAX_K 11
#define oo (1e15)
#define EPS (1e-9)

int n, m, k;
vector<pid> adj[MAX_N];
double d[MAX_N][MAX_K];

bool equal(double x, double y) {
    return abs(x - y) < EPS;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m >> k;
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    for (int u = 2; u <= n; u++)
        for (int i = 0; i <= k; i++)
            d[u][i] = +oo;

    priority_queue<pdii, vector<pdii>, greater<pdii>> Heap;
    Heap.push({0, {1, 0}});
    while (Heap.size()) {
        double du = Heap.top().first;
        int u = Heap.top().second.first, idx = Heap.top().second.second;
        Heap.pop();

        if (u == n) break;
        if (!equal(d[u][idx], du)) continue;
        for (auto [v, w]: adj[u]) {
            for (int i = idx; i <= k; i++) {
                double new_cost = du + w / (1 << (i - idx));
                if (d[v][i] > new_cost) {
                    d[v][i] = new_cost;
                    Heap.push({d[v][i], {v, i}});
                }
            }
        }
    }

    cout << fixed << setprecision(2) << d[n][k] << "\n";
}