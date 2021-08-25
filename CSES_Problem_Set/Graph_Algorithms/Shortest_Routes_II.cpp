// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
const long long oo = 1e15;
#define MAX_N 502
 
int n, m, q;
long long d[MAX_N][MAX_N]; 
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> q;
	for (int u = 1; u <= n; u++)
		for (int v = 1; v <= n; v++) 
			if (u != v) d[u][v] = +oo;
 
	while (m--) {
		int u, v;
		long long l;
		cin >> u >> v >> l;
		d[u][v] = min(d[u][v], l);
		d[v][u] = d[u][v];
	}
 
	for (int k = 1; k <= n; k++)
		for (int u = 1; u <= n; u++)
			for (int v = 1; v <= n; v++)
				d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
 
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << (d[u][v] != +oo ? d[u][v] : -1) << "\n";
	}
}