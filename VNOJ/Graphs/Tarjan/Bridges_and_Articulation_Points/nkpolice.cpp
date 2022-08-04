// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define LOG_N 22

int n, m, q, timer;
vector<int> adj[MAX_N];
int low[MAX_N], num[MAX_N], tail[MAX_N];
int depth[MAX_N], par[LOG_N + 1][MAX_N];
bool isAP[MAX_N];

void dfs(int u) {
    num[u] = low[u] = ++timer;
    int child = 0;
    for (int v: adj[u]) {
        if (v == par[0][u]) continue;
        if (num[v]) {
            low[u] = min(low[u], num[v]);
            continue;
        }
        child++;
        par[0][v] = u, depth[v] = depth[u] + 1;
        dfs(v);
        low[u] = min(low[u], low[v]);
        if (low[v] >= num[u] && (par[0][u] || child > 1))
            isAP[u] = true;
    }
    tail[u] = timer;
}

bool inSubTree(int root, int u) {
    return num[root] <= num[u] && num[u] <= tail[root];
}

int findPar(int root, int u) {
    for (int exp = LOG_N; exp >= 0; exp--)
        if (depth[par[exp][u]] > depth[root]) 
            u = par[exp][u];
    return u;
}

bool query_1(int a, int b, int g1, int g2) {
    // Swap to make sure g1 is parents of g2
    if (num[g1] > num[g2]) swap(g1, g2);

    // If edge(g1, g2) isn't bridge, answer will be true
    if (low[g2] != num[g2]) return true;

    // Else, check if g1 and g2 are in the same connected component
    if (inSubTree(g2, a) && inSubTree(g2, b)) return true;
    if (!inSubTree(g2, a) && !inSubTree(g2, b)) return true;
    return false;
}

bool query_2(int a, int b, int g) { 
    // If vertex g isn't articulation point, answer will be true
    if (!isAP[g]) return true;

    // Find pa & pb
    int pa = -1, pb = -1;
    if (inSubTree(g, a)) pa = findPar(g, a);
    if (inSubTree(g, b)) pb = findPar(g, b);

    // Check if both a and b are not in the subtree root g
    if (pa == -1 && pb == -1) return true;

    // Check if a and b in the same subtree root pa (pb)
    if (pa == pb) return true;

    // Check if a and b will in the same components after remove g
    if (pa == -1 && low[pb] < num[g]) return true;
    if (pb == -1 && low[pa] < num[g]) return true;
    if (pa && low[pa] < num[g] && pb && low[pb] < num[g]) return true;

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> n >> m; m--;) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 1;
    dfs(1);
    par[1][0] = 1;
    
    // Init Sparse Table
    for (int exp = 1; exp <= LOG_N; exp++) 
        for (int u = 1; u <= n; u++)
            par[exp][u] = par[exp - 1][par[exp - 1][u]];

    for (cin >> q; q--;) {
        int tp, a, b, g, g1, g2;
        cin >> tp;
        if (tp == 1) {
            cin >> a >> b >> g1 >> g2;
            cout << (query_1(a, b, g1, g2) ? "yes\n" : "no\n");
        } else {
            cin >> a >> b >> g;
            cout << (query_2(a, b, g) ? "yes\n" : "no\n");
        }
    }
}