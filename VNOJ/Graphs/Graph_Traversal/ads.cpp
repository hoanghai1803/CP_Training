// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 2222

int n, m, ncc;
vector<int> adj[MAX_N];
bool visited[MAX_N];

void dfs(int u) {
    visited[u] = true;
    for (int v: adj[u]) 
        if (!visited[v]) dfs(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 1; u <= n; u++)
        if (!visited[u]) {
            ncc++;
            dfs(u);
        }

    cout << m - n + ncc << "\n";
}