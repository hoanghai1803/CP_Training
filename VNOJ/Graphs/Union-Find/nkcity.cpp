// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1003
#define MAX_M 10004

struct Edge {
    int u, v, w;
    bool operator < (Edge rhs) {
        return w < rhs.w;
    }
};

int n, m, cnt;
int par[MAX_N];
vector<Edge> edges;

int findRoot(int u) {
    if (par[u] == u)
        return u;
    return par[u] = findRoot(par[u]);
}

void Union(int u, int v) {
    if ((u = findRoot(u)) == (v = findRoot(v))) return;
    par[u] = v, cnt++;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> n >> m; m--;) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end());

    for (int u = 1; u <= n; u++) par[u] = u;
    for (auto e: edges) {
        Union(e.u, e.v);
        if (cnt == n - 1) {
            cout << e.w << "\n";
            return 0;
        }
    }
}