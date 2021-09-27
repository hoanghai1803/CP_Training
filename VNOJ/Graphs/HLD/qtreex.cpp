// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define oo (int)1e9
#define MAX_N 10004
#define LOG_N 22

int T, n;
int weight[MAX_N], children[MAX_N], depth[MAX_N];
int par[LOG_N + 1][MAX_N];
vector<pair<int, int>> adj[MAX_N], edges;

/* HLD Base */
int nChains, nArr;
int headChain[MAX_N], inChain[MAX_N], posInArr[MAX_N];
int isVtx[MAX_N];

/* Segment Tree Base */
struct Node {
    int maxVal, minVal;
    bool lazy;
} Nodes[4 * MAX_N];

/* Traversal the Tree */
void dfs(int u) {
    for (auto vtx: adj[u]) {
        int v = vtx.first, w = vtx.second;
        if (v == par[0][u]) continue;
        par[0][v] = u;
        depth[v] = depth[u] + 1;
        weight[v] = w;
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
    isVtx[nArr] = u;

    // Find the heavy child vertex of vertex u
    int heavyVtx = -1;
    for (auto vtx: adj[u]) {
        int v = vtx.first;
        if (v == par[0][u]) continue;
        if (heavyVtx == -1 || children[v] > children[heavyVtx]) heavyVtx = v;
    }
    if (heavyVtx != -1) hld(heavyVtx);

    for (auto vtx: adj[u]) {
        int v = vtx.first;
        if (v == par[0][u] || v == heavyVtx) continue;
        nChains++;
        hld(v);
    }
}

/* Segment Tree */
void build_ST(int id, int L, int R) {
    Node& node = Nodes[id];
    int w = weight[isVtx[L]];
    if (L == R) {
        node = {w, w, 0};
        return;
    }

    int M = (L + R) >> 1;
    build_ST(id * 2, L, M);
    build_ST(id * 2 + 1, M + 1, R);
    node.maxVal = max(Nodes[id * 2].maxVal, Nodes[id * 2 + 1].maxVal);
    node.minVal = min(Nodes[id * 2].minVal, Nodes[id * 2 + 1].minVal);
}

void propagation(int id) {
    for (int k = 0; k <= 1; k++) {
        Node& node = Nodes[id * 2 + k];
        node = {-node.minVal, -node.maxVal, !node.lazy};
    }
    Nodes[id].lazy = 0;
}

void change_ST(int id, int L, int R, int pos, int val) {
    Node& node = Nodes[id];
    if (L > pos || R < pos) return;
    if (L == R) {
        node = {val, val, 0};
        return;
    }
    if (node.lazy) propagation(id);

    int M = (L + R) >> 1;
    change_ST(id * 2, L, M, pos, val);
    change_ST(id * 2 + 1, M + 1, R, pos, val);
    node.maxVal = max(Nodes[id * 2].maxVal, Nodes[id * 2 + 1].maxVal);
    node.minVal = min(Nodes[id * 2].minVal, Nodes[id * 2 + 1].minVal);
}

void negate_ST(int id, int L, int R, int u, int v) {
    Node& node = Nodes[id];
    if (u > v || L > v || R < u) return;
    if (L >= u && R <= v) {
        node = {-node.minVal, -node.maxVal, !node.lazy};
        return;
    }
    if (node.lazy) propagation(id);

    int M = (L + R) >> 1;
    negate_ST(id * 2, L, M, u, v);
    negate_ST(id * 2 + 1, M + 1, R, u, v);
    node.maxVal = max(Nodes[id * 2].maxVal, Nodes[id * 2 + 1].maxVal);
    node.minVal = min(Nodes[id * 2].minVal, Nodes[id * 2 + 1].minVal);
}

int get_ST(int id, int L, int R, int u, int v) {
    if (u > v || L > v || R < u) return -oo;
    if (L >= u && R <= v) return Nodes[id].maxVal;
    if (Nodes[id].lazy) propagation(id);

    int M = (L + R) >> 1;
    return max(get_ST(id * 2, L, M, u, v), get_ST(id * 2 + 1, M + 1, R, u, v));
}

/* Update and Query HLD */
void negatePath(int u, int p) {
    while (1) {
        int uChain = inChain[u], pChain = inChain[p];
        if (uChain == pChain) {
            negate_ST(1, 1, n, posInArr[p] + 1, posInArr[u]);
            break;
        }
        negate_ST(1, 1, n, posInArr[headChain[uChain]], posInArr[u]);
        u = par[0][headChain[uChain]];
    }
}

int query(int u, int p) {
    int maxVal = -oo;
    while (1) {
        int uChain = inChain[u], pChain = inChain[p];
        if (uChain == pChain) {
            maxVal = max(maxVal, get_ST(1, 1, n, posInArr[p] + 1, posInArr[u]));
            break;
        }
        maxVal = max(maxVal, get_ST(1, 1, n, posInArr[headChain[uChain]], posInArr[u]));
        u = par[0][headChain[uChain]];
    }
    return maxVal;
}

/* Initialization for each testcase */
void init() {
    cin >> n;
    for (int u = 1; u <= n; u++) adj[u].clear();
    edges.clear();
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v});
    }

    // Init for LCA
    memset(par, 0, sizeof(par));
    memset(children, 0, sizeof(children));
    depth[1] = 1;
    dfs(1);
    for (int k = 1; k <= LOG_N; k++)
        for (int u = 1; u <= n; u++) 
            par[k][u] = par[k - 1][par[k - 1][u]];

    // Init for HLD
    nChains = 1, nArr = 0;
    memset(headChain, 0, sizeof(headChain));
    hld(1);

    // Init for Segment Tree
    for (int id = 1; id < 4 * MAX_N; id++) Nodes[id] = {-oo, +oo, 0};
    build_ST(1, 1, n);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> T; T--;) {
        init();
        string type;
        for (int i, val, u, v; cin >> type;) {
            if (type == "DONE") break;

            if (type == "CHANGE") {
                cin >> i >> val;
                int u = edges[i - 1].first, v = edges[i - 1].second;
                if (v == par[0][u]) swap(u, v);
                change_ST(1, 1, n, posInArr[v], val);
                continue;
            }

            cin >> u >> v;
            int _lca = lca(u, v);
            if (type == "NEGATE") {
                negatePath(u, _lca);
                negatePath(v, _lca);
                continue;
            }
            cout << (u == v ? 0 : max(query(u, _lca), query(v, _lca))) << "\n";
        }
    }
}