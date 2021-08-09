#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 100005
 
int n, m;
vector<int> adj[MAX_N], roots;
bool visited[MAX_N];
int ncc; // number of connected components
 
void dfs(int u) {
    visited[u] = true;
    for (int v: adj[u]) 
        if (!visited[v]) dfs(v);
}
 
int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
    for (int u = 1; u <= n; u++)
        if (!visited[u]) {
            ncc++;
            roots.push_back(u);
            dfs(u);
        }
 
	cout << ncc - 1 << "\n";
    for (int i = 1; i < roots.size(); i++) 
        cout << 1 << " " << roots[i] << "\n";
}