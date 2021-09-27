// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define MAX_N 100005

int n, q;
int par[MAX_N], children[MAX_N];
vector<int> adj[MAX_N];
int Nodes[4 * MAX_N]; // Segment tree

/* HLD Base */
int nChains = 1, nArr;
int headChain[MAX_N], inChain[MAX_N], posInArr[MAX_N];
int isVtx[MAX_N];
bool arr[MAX_N];

/* Dfs tree for calculating children of each vertex */
void dfs(int u) {
    for (int v: adj[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        dfs(v);
        children[u] += children[v] + 1;
    }
}

/* Init HLD */
void hld(int u) {
    if (!headChain[nChains]) headChain[nChains] = u;
    inChain[u] = nChains;
    posInArr[u] = ++nArr;
    isVtx[nArr] = u;

    // Find the heavy child vertex of vertex u
    int heavyVtx = -1;
    for (int v: adj[u]) {
        if (v == par[u]) continue;
        if (heavyVtx == -1 || children[v] > children[heavyVtx]) heavyVtx = v;
    }
    if (heavyVtx != -1) hld(heavyVtx); 

    for (int v: adj[u]) {
        if (v == par[u] || v == heavyVtx) continue;
        nChains++;
        hld(v);
    }
}

/* Segment Tree */
int update(int id, int L, int R, int pos) {
    if (R < pos || L > pos) return Nodes[id];
    if (L == R) {
        if (arr[pos]) {
            arr[pos] = 0;
            return (Nodes[id] = +oo);
        } else {
            arr[pos] = 1;
            return (Nodes[id] = pos);
        }
    }

    int M = (L + R) >> 1;
    return (Nodes[id] = min(update(id * 2, L, M, pos), update(id * 2 + 1, M + 1, R, pos)));
}

int getMin(int id, int L, int R, int u, int v) {
    if (R < u || L > v) return +oo;
    if (L >= u && R <= v) return Nodes[id];

    int M = (L + R) >> 1;
    return min(getMin(id * 2, L, M, u, v), getMin(id * 2 + 1, M + 1, R, u, v));
}

/* Query HLD */
void query(int u) {
    int minPos = +oo;
    while (1) {
        int uChain = inChain[u];
        if (uChain == 1) {
            minPos = min(minPos, getMin(1, 1, n, 1, posInArr[u]));
            break;
        }
        minPos = min(minPos, getMin(1, 1, n, posInArr[headChain[uChain]], posInArr[u]));
        u = par[headChain[uChain]];
    }
    cout << (minPos == +oo ? -1 : isVtx[minPos]) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // Initialization
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i < 4 * MAX_N; i++) Nodes[i] = +oo;
    dfs(1);
    hld(1);

    // Queries
    while (q--) {
        int t, u;
        cin >> t >> u;
        if (t) query(u);
        else update(1, 1, n, posInArr[u]);
    }
}