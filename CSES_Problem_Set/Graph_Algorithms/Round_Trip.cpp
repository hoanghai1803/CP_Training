// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 100005
 
int n, m;
bool visited[MAX_N];
int trace[MAX_N];
vector<int> adj[MAX_N];
bool available;
int keyCity;
 
void init() {
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
 
void dfs(int u) {
	for (int v: adj[u]) {
		if (available) return;
 
		if (visited[v]) {
			if (v == trace[u]) continue;
			available = true;
			trace[v] = u;
			keyCity = v;
			return;
		}
 
		trace[v] = u;
		visited[v] = true;
		dfs(v);
	}
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	init();
 
	for (int u = 1; u <= n; u++) 
		if (!visited[u]) {
			visited[u] = true;
			dfs(u);
		}
 
	if (!available) {
		cout << "IMPOSSIBLE";
		return 0;
	}
 
	vector<int> route;
	route.push_back(keyCity);
	int u = trace[keyCity];
	while (u != keyCity) route.push_back(u), u = trace[u];
	route.push_back(keyCity);
	
	cout << route.size() << "\n";
	for (int u: route) cout << u << " ";
}