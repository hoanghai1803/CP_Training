// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 100005
 
int n, m;
bool visited[MAX_N];
int trace[MAX_N];
vector<int> adj[MAX_N];
 
void init() {
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
 
bool bfs() {
	queue<int> Q;
	visited[1] = true, Q.push(1);
	
	while (Q.size()) {
		int u = Q.front();
		Q.pop();
 
		for (int v: adj[u]) {
			if (v == n) {
				trace[v] = u;
				return true;
			}
 
			if (!visited[v]) {
				visited[v] = true;
				trace[v] = u;
				Q.push(v);
			}
		}
	}
 
	return false;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	init();	
	if (!bfs()) {
		cout << "IMPOSSIBLE";
		return 0;
	}
 
	vector<int> route;
	while (n) {
		route.push_back(n);
		n = trace[n];
	}	
 
	cout << route.size() << "\n";
	reverse(route.begin(), route.end());	
	for (int u: route) cout << u << " ";
}