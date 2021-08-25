// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 100005
 
int n, m;
vector<int> friends[MAX_N];
bool checked[MAX_N], inFirstGroup[MAX_N];
bool available = true;
 
void init() {
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		friends[u].push_back(v);
		friends[v].push_back(u);
	}
}
 
void dfs(int u) {
	for (int v: friends[u]) {
		if (checked[v]) {
			if (inFirstGroup[u] == inFirstGroup[v]) available = false;
			continue;
		}		
		inFirstGroup[v] = !inFirstGroup[u];
		checked[v] = true;
		dfs(v);
	}
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	init();
	for (int u = 1; u <= n; u++) 
		if (!checked[u]) {
			inFirstGroup[u] = true;
			checked[u] = true;
			dfs(u);
		}
	
	if (available) {
		for (int u = 1; u <= n; u++)
			cout << (inFirstGroup[u] ? 1 : 2) << " ";
	} else {
		cout << "IMPOSSIBLE";
	}
}