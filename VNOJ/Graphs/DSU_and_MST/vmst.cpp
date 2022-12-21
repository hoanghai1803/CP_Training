// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1111

int n, m;
vector<int> adj[MAX_N];
int par[MAX_N];
vector<pair<int, int>> ans;
pair<int, int> newEdge;

void bfs(int root) {
    queue<int> Q;
    Q.push(root);
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (int v: adj[u]) {
            if (v == root || par[v]) continue;
            par[v] = u;
            ans.push_back({u, v});
            Q.push(v);
        }
    }
}

void solve() {
    for (int u = 1; u <= n; u++) 
        for (int v: adj[u]) {
            if (par[u] == v || par[v] == u) continue;
            newEdge = {u, v};
            return;
        }
}

void exportTree(int vtx) {
    for (int u = 1; u <= n; u++) 
        for (int v: adj[u]) 
            if (par[v] == u) {
                if (v == vtx)
                    continue;
                else 
                    cout << u << " " << v << "\n";
            }
    if (vtx) cout << newEdge.first << " " << newEdge.second << "\n";
}


int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    solve();
    
    cout << "3\n";
    exportTree(0);
    exportTree(newEdge.first);
    exportTree(newEdge.second);
}