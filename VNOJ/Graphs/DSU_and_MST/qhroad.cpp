// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

int n, m, q, ncc;
int par[MAX_N], rmRoads[MAX_N], ans[MAX_N];
pair<int, int> edges[MAX_N];
bool rm[MAX_N];

int findRoot(int u) {
    if (par[u] == u)
        return u;
    return (par[u] = findRoot(par[u]));
}

void Union(int u, int v) {
    if ((u = findRoot(u)) == (v = findRoot(v))) 
        return;
    par[u] = v, ncc--;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // Init
    cin >> n >> m >> q;
    ncc = n;
    for (int i = 1; i <= m; i++)
        cin >> edges[i].first >> edges[i].second;
    for (int i = 1; i <= q; i++) {
        cin >> rmRoads[i];
        rm[rmRoads[i]] = true;
    }
    for (int u = 1; u <= n; u++) 
        par[u] = u;

    // DSU
    for (int i = 1; i <= m; i++)
        if (!rm[i]) Union(edges[i].first, edges[i].second);
    for (int i = q; i; i--) {
        ans[i] = ncc;
        Union(edges[rmRoads[i]].first, edges[rmRoads[i]].second);
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << "\n";
    
}