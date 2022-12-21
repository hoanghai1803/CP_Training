// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MAX_N 100005

int n, m;
vector<int> adj[MAX_N];
int color[MAX_N];
bool is_bipartite;
int64 red, blue;

void dfs(int u) {
    for (int v : adj[u]) {
        if (color[v]) {
            if (color[v] == color[u]) is_bipartite = false;
            continue;
        }
        color[v] = color[u] ^ 3;
        red += color[v] == 1;
        blue += color[v] == 2;
        dfs(v);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int64 ans = 0;
    for (int u = 1; u <= n; u++) {
        if (color[u]) continue;
        is_bipartite = true;
        color[u] = 1, red = 1, blue = 0;
        dfs(u);
        if (!is_bipartite)
            ans += (red + blue) * (red + blue);
        else
            ans += red * red + blue * blue;
    }
    cout << ans << "\n";
}