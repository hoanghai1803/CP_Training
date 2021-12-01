// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MAX_N 200005

int n, q;
int vtx[MAX_N], par[MAX_N], children[MAX_N];
vector<int> adj[MAX_N];
int64 bit[MAX_N]; // Fenwick Tree

/* HLD Base */
int nChains = 1, nArr;
int headChain[MAX_N], inChain[MAX_N], posInArr[MAX_N];

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

/* Fenwick Tree */
void update(int p, int v) {
    for (int i = p; i <= n; i += i & -i)
        bit[i] += v;
}

int64 getSum(int p) {
    int64 sum = 0;
    for (int i = p; i; i -= i & -i)
        sum += bit[i];
    return sum;
}

/* Query HLD */
void query(int u) {
    int64 sum = 0;
    while (1) {
        int uChain = inChain[u];
        if (uChain == 1) {
            sum += getSum(posInArr[u]);
            break;
        }
        sum += getSum(posInArr[u]) - getSum(posInArr[headChain[uChain]] - 1);
        u = par[headChain[uChain]];
    }
    cout << sum << "\n";
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

    dfs(1);
    hld(1);
    for (int u = 1; u <= n; u++)
        update(posInArr[u], vtx[u]);

    // Queries
    while (q--) {
        int id, s, x;
        cin >> id;
        if (id == 1) {
            cin >> s >> x;
            update(posInArr[s], x - vtx[s]);
            vtx[s] = x;
        } else {
            cin >> s;
            query(s);
        }
    }
}