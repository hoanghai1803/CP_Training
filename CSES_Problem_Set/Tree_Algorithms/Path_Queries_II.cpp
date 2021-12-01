// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
#define oo INT_MAX
#define MAX_N 200005
#define LOG_N 20
 
int n, q;
int vtx[MAX_N], depth[MAX_N], children[MAX_N];
int par[LOG_N][MAX_N];
vector<int> adj[MAX_N];
int ST[4 * MAX_N]; // Segment Tree
 
/* HLD Base */
int nChains = 1, nArr;
int headChain[MAX_N], inChain[MAX_N], posInArr[MAX_N];
 
/* Dfs tree for calculating children of each vertex */
void dfs(int u) {
    for (int v: adj[u]) {
        if (v == par[0][u]) continue;
        par[0][v] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
        children[u] += children[v] + 1;
    }
}

/* LCA Query */
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = LOG_N; k >= 0; k--) 
        if (depth[par[k][u]] >= depth[v]) u = par[k][u];
    if (u == v) return u;
    for (int k = LOG_N; k >= 0; k--) 
        if (par[k][u] != par[k][v]) u = par[k][u], v = par[k][v];
    return par[0][u];
}
 
/* Init HLD */
void hld(int u) {
    if (!headChain[nChains]) headChain[nChains] = u;
    inChain[u] = nChains;
    posInArr[u] = ++nArr;
 
    // Find the heavy child vertex of vertex u
    int heavyVtx = -1;
    for (int v: adj[u]) {
        if (v == par[0][u]) continue;
        if (heavyVtx == -1 || children[v] > children[heavyVtx]) heavyVtx = v;
    }
    if (heavyVtx != -1) hld(heavyVtx); 
 
    for (int v: adj[u]) {
        if (v == par[0][u] || v == heavyVtx) continue;
        nChains++;
        hld(v);
    }
}
 
/* Segment Tree */
void update(int id, int l, int r, int p, int v) {
    if (p < l || p > r) return;
    if (l == r) {
        ST[id] = v;
        return;
    }

    int m = (l + r) >> 1;
    update(id * 2, l, m, p, v);
    update(id * 2 + 1, m + 1, r, p, v);
    ST[id] = max(ST[id * 2], ST[id * 2 + 1]);
}
 
int getMax(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return -oo;
    if (u <= l && v >= r) return ST[id];

    int m = (l + r) >> 1;
    return max(getMax(id * 2, l, m, u, v), getMax(id * 2 + 1, m + 1, r, u, v));
}
 
/* Query HLD */
int query(int u, int p) {
    int maxVal = -oo;
    while (1) {
        int uChain = inChain[u], pChain = inChain[p];
        if (uChain == pChain) {
            maxVal = max(maxVal, getMax(1, 1, n, posInArr[p], posInArr[u]));
            break;
        }

        if (u == headChain[uChain]) 
            maxVal = max(maxVal, vtx[u]);
        else 
            maxVal = max(maxVal, getMax(1, 1, n, posInArr[headChain[uChain]], posInArr[u]));
        u = par[0][headChain[uChain]];
    }
    return maxVal;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    // Initialization
    cin >> n >> q;
    for (int u = 1; u <= n; u++)
        cin >> vtx[u];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    depth[1] = 1;
    dfs(1);
    for (int k = 1; k <= LOG_N; k++)
        for (int u = 1; u <= n; u++) 
            par[k][u] = par[k - 1][par[k - 1][u]];
    hld(1);
    for (int i = 1; i < 4 * MAX_N; i++)
        ST[i] = -oo;
    for (int u = 1; u <= n; u++)
        update(1, 1, n, posInArr[u], vtx[u]);
 
    // Queries
    while (q--) {
        int id, s, x, a, b;
        cin >> id;
        if (id == 1) {
            cin >> s >> x;
            update(1, 1, n, posInArr[s], x);
            vtx[s] = x;
        } else {
            cin >> a >> b;
            int __lca = lca(a, b);
            cout << max(query(a, __lca), query(b, __lca)) << " ";
        }
    }
}