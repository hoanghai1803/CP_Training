// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1003

int n, m;
int par[MAX_N];
vector<pair<int, pair<int, int>>> edges;

int findRoot(int u) {
    if (par[u] == u) 
        return u;
    return par[u] = findRoot(par[u]);
}

void Union(int u, int v) {
    if ((u = findRoot(u)) == (v = findRoot(v)))
        return;
    par[u] = v;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> n >> m; m--;) {
        int u, v, w; 
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    for (int u = 1; u <= n; u++) par[u] = u;

    for (auto e: edges) {
        Union(e.second.first, e.second.second);
        if (findRoot(1) == findRoot(n)) {
            cout << e.first << "\n";
            break;
        }
    }
}