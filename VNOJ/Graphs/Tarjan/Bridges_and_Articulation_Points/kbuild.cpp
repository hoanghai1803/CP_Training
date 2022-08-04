// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005

int n, m, bridges;
int timer;
int num[MAX_N], low[MAX_N];
vector<int> adj[MAX_N];
unordered_map<int, int> numEdges[MAX_N];

void dfs(int u, int p) {
    num[u] = low[u] = ++timer;
    for (int v: adj[u]) {
        if (v == p) continue;
        if (num[v]) {
            low[u] = min(low[u], num[v]);
            continue;
        }
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        bridges += num[v] == low[v] && numEdges[min(u, v)][max(u, v)] < 2;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        numEdges[u][v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        numEdges[u][v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    cout << bridges << "\n";
}