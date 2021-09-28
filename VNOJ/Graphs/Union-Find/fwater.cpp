// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 333

struct Edge {
    int u, v, w;
    bool operator < (Edge rhs) {
        return w < rhs.w;
    }
};

int n, m, res;
int par[MAX_N];
vector<Edge> edges;

int findRoot(int u) {
    if (par[u] == u)
        return u;
    return par[u] = findRoot(par[u]);
}

void Union(Edge e) {
    int u = findRoot(e.u), v = findRoot(e.v), w = e.w;
    if (u == v) return;
    res += w, par[u] = v;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int u = 1; u <= n; u++) par[u] = u;
    for (int u = 0; u <= n; u++)
        for (int v = 1; v <= n; v++) {
            int w;
            cin  >> w;
            if (u < v) edges.push_back({u, v, w});
        }

    sort(edges.begin(), edges.end());
    for (auto e: edges) Union(e);
    cout << res << "\n";
}