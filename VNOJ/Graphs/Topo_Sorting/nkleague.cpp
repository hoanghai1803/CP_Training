// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1111

int n; 
vector<int> adj[MAX_N]; 
vector<bool> visited;
vector<int> ans;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) 
        if (!visited[v]) dfs(v);
    ans.push_back(u);
}

void topo_sort() {
    visited.assign(n, false);
    for (int u = 0; u < n; u++) 
        if (!visited[u]) dfs(u);
    reverse(ans.begin(), ans.end());
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    string s;
    for (int u = 0; u < n; u++) {
        cin >> s;
        for (int v = 0; v < n; v++) 
            if (s[v] == '1') adj[u].push_back(v);
    }

    topo_sort();
    for (int u: ans) cout << u + 1 << " ";
}