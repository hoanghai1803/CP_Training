// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define MAX_N 100005
#define MAX_M 100005
#define LOG_N 22

struct edge {
    int u, v, w;
    bool inMST; // In Maximum Spanning Tree

    bool operator < (edge rhs) {
        return w > rhs.w;
    }
};

int n, m;
int pa[MAX_N];
vector<edge> edges;
vector<pair<int, int>> adj[MAX_N];
int depth[MAX_N];
int Par[LOG_N + 1][MAX_N], minPath[LOG_N + 1][MAX_N];
long long res = 0;

int findRoot(int u) {
    if (pa[u] < 0)
        return u;
    return pa[u] = findRoot(pa[u]);
}

void Union(edge& e) {    
    int u = findRoot(e.u), v = findRoot(e.v);
    if (u == v) return;
    pa[u] = v;
    e.inMST = true;
    adj[u].push_back({v, e.w});
    adj[v].push_back({u, e.w});
}

void dfs(int u) {
    for (auto child: adj[u]) {
        int v = child.first, l = child.second;
        if (v == Par[0][u]) continue;
        depth[v] = depth[u] + 1;
        minPath[0][v] = l;
        Par[0][v] = u;
        dfs(v);
    }
}

void minimize(int& target, int val1, int val2 = +oo) {
    target = min(target, min(val1, val2));
}

void Calc(edge e) {
    int u = e.u, v = e.v, w = e.w;
    if (depth[u] < depth[v]) swap(u, v);
    int cost = +oo;

    for (int k = LOG_N; k >= 0; k--)
        if (depth[Par[k][u]] >= depth[v]) {
            minimize(cost, minPath[k][u]);
            u = Par[k][u];
        }

    if (u == v) {
        res += max(cost - w, 0);
        return;
    }

    for (int k = LOG_N; k >= 0; k--) 
        if (Par[k][u] != Par[k][v]) {
            minimize(cost, minPath[k][u], minPath[k][v]);
            u = Par[k][u], v = Par[k][v];
        }

    minimize(cost, minPath[0][u], minPath[0][v]);
    res += max(cost - w, 0);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    memset(pa, -1, sizeof(pa));
    for (int u, v, w; m--;) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w, false});
    }

    sort(edges. begin(), edges.end());
    for (auto& e: edges) Union(e);

    depth[1] = 1;
    dfs(1);
    for (int k = 1; k <= LOG_N; k++)
        for (int u = 1; u <= n; u++) {
            minPath[k][u] = min(minPath[k - 1][u], minPath[k - 1][Par[k - 1][u]]);
            Par[k][u] = Par[k - 1][Par[k - 1][u]];
        }

    for (auto e: edges) {
        if (e.inMST) continue;
        Calc(e);
    }
    cout << res << "\n";
}