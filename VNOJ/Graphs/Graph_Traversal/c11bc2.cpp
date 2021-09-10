// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10004

int n, q;
vector<int> adj[MAX_N];
int numCC;
int CC[MAX_N];

void dfs(int u) {
    CC[u] = numCC;
    for (int v: adj[u])
        if (!CC[v]) dfs(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q;
    for (int u = 2, v, t; u <= n; u++) {
        cin >> v >> t;
        if (t == 1) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    for (int u = 1; u <= n; u++) 
        if (!CC[u]) {
            numCC++;
            dfs(u);
        }

    for (int u, v; q--;) {
        cin >> u >> v;
        cout << (CC[u] != CC[v] ? "YES\n" : "NO\n");
    }
}
