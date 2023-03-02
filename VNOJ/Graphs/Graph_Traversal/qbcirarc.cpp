// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define MAX_N 1003

int n, m;
ii rmEdge;
vector<int> adj[MAX_N];
int numArc[MAX_N][MAX_N];

// For finding cycle
// 0 for unvisited, 1 for visited, 2 for visited but already exited.
vector<char> color;
vector<int> par;
int cycle_start, cycle_end;

bool dfs_color(int u) {
    color[u] = 1;
    for (int v : adj[u]) {
        if (rmEdge == ii(u, v)) continue;
        if (color[v] == 0) {
            par[v] = u;
            if (dfs_color(v)) return true;
        } else if (color[v] == 1) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
    }
    color[u] = 2;
    return false;
}

void find_cycle() {
    color.assign(n + 1, 0);
    par.assign(n + 1, -1);
    cycle_start = -1;

    for (int v = 1; v <= n; v++) {
        if (color[v] == 0 && dfs_color(v)) break;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // Input
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (numArc[u][v]) {
            numArc[u][v]++;
            continue;
        }
        numArc[u][v] = 1;
        adj[u].push_back(v);
    }

    find_cycle();
    if (cycle_start == -1) {
        cout << "-1\n";
        return 0;
    }

    vector<ii> cycle;
    cycle.push_back({cycle_end, cycle_start});
    for (int v = cycle_end; v != cycle_start; v = par[v])
        cycle.push_back({par[v], v});

    // Finding important arcs
    vector<ii> ans;
    for (ii e : cycle) {
        if (numArc[e.first][e.second] > 1) continue;
        rmEdge = e;
        find_cycle();
        if (cycle_start == -1) ans.push_back(e);
    }

    // Print out the answer
    if (ans.empty()) {
        cout << "-1\n";
    } else {
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (ii e : ans) cout << e.first << " " << e.second << "\n";
    }
}