// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

#define MAX_N 100005
#define MOD 1000000007

int n;
vector<ii> adj[MAX_N];
int64 sum[MAX_N], res = 0;

void dfs(int u, int par) {
    for (auto e: adj[u]) {
        int v = e.first, w = e.second;
        if (v == par) continue;
        dfs(v, u);
        res = (res + (w * sum[v] + w) % MOD * sum[u]) % MOD;
        sum[u] = (sum[u] + w * sum[v] + w) % MOD;
    }
    res = (res + sum[u]) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1, 0);
    cout << res << "\n";
}