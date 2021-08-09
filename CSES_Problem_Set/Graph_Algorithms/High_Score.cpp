#include <bits/stdc++.h>
 
using namespace std;
 
const long long oo = 1e15;
#define MAX_N 2555
 
int n, m;
long long d[MAX_N];
bool res = true;
bool visited[MAX_N], isNegative[MAX_N];
 
struct Tunnel {
	int src, dest;
	int score;
};
 
vector<Tunnel> tunnels;
vector<int> tunnels_reverse[MAX_N];
 
void init() {
	cin >> n >> m;
	while (m--) {
		int u, v, score;
		cin >> u >> v >> score;
		Tunnel t = {u, v, -score};
		tunnels.push_back(t);		
		tunnels_reverse[v].push_back(u);
	} 
	for (int u = 2; u <= n; u++) d[u] = +oo;
}
 
void FordBellman() {
	for (int i = 1; i < n; i++) {
		for (Tunnel t: tunnels) {
			int u = t.src, v = t.dest;
			int score = t.score;
			if (d[u] != +oo && d[u] + score < d[v])
				d[v] = d[u] + score;
		}	
	}
 
	// Find negative cycles in graph
	for (Tunnel t: tunnels) {
		int u = t.src, v = t.dest;
		int score = t.score;
		if (d[u] != +oo && d[u] + score < d[v]) isNegative[v] = true;
	}
}
 
void dfs(int u) {
	for (int v: tunnels_reverse[u]) {
		if (isNegative[v]) res = false;
		if (!res) return;
		if (visited[v]) continue;
		visited[v] = true;
		dfs(v);
	}
}
 
int main() {
	init();
	FordBellman();	
	dfs(n);
	cout << -(res ? d[n] : 1);
}