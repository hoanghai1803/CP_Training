// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

int m, n, q;
int par[MAX_N], cnt[MAX_N], res[MAX_N];
unordered_map<int, int> cc[MAX_N];

int findRoot(int u) {
	if (par[u] == u) 
		return u;
	return par[u] = findRoot(par[u]);
}

void Union(int u, int v, int times) {
	if ((u = findRoot(u)) == (v = findRoot(v))) return;
	if (cc[u].size() > cc[v].size()) swap(u, v);
	par[u] = v;

	for (auto it: cc[u]) {
		int game = it.first, stu = it.second;
		cc[v][game] += stu;
		if (res[game] == -1 && cc[v][game] == cnt[game])
			res[game] = times;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m >> q;
	for (int u = 1; u <= n; u++) {
		par[u] = u;
		int game;
		cin >> game;
		cc[u][game] = 1, cnt[game]++;
	}

	for (int i = 1; i <= m; i++) 
		res[i] = (cnt[i] == 1 ? 0 : -1);

	for (int times = 1; times <= q; times++) {
		int u, v;
		cin >> u >> v;
		Union(u, v, times);
	}

	for (int i = 1; i <= m; i++) 
		cout << res[i] << "\n";
}