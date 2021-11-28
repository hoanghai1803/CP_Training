// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MAX_N 200005

int n, root;
vector<int> adj[MAX_N];
int depth[MAX_N], subtree[MAX_N];
int64 sum[MAX_N];

void dfs(int u, int par) {
    subtree[u] = 1;
    for (int v: adj[u]) {
        if (v == par) continue;
        depth[v] = depth[u] + 1;
        sum[root] += depth[v];
        dfs(v, u);
        subtree[u] += subtree[v];
    }
}

void calc(int u, int par) {
    for (int v: adj[u]) {
        if (v == par) continue;
        sum[v] = sum[u] + ((n - subtree[v]) - subtree[v]);
        calc(v, u);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    root = 1;
    dfs(root, 0);
    calc(root, 0);

    for (int u = 1; u <= n; u++) 
        cout << sum[u] << " ";
    cout << "\n";
}