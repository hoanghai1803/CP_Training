// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

int n, x, sum;
int dist[MAX_N];
vector<pair<int, int>> adj[MAX_N];

void dfs(int u, int par) {
    for (auto [v, c]: adj[u]) {
        if (v == par) continue;
        dist[v] = dist[u] + c;
        dfs(v, u);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> x;
    for (int i = 1; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        sum += c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    dfs(1, -1);
    int farthest_vtx = max_element(dist + 1, dist + 1 + n) - dist;
    dist[farthest_vtx] = 0;
    dfs(farthest_vtx, -1);
    farthest_vtx = max_element(dist + 1, dist + 1 + n) - dist;
    cout << 2 * sum - dist[farthest_vtx] << "\n";
}