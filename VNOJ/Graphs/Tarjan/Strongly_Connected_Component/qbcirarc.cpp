// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define MAX_N 1003

int n, m;
ii rmEdge;
vector<int> adj[MAX_N];
int numArc[MAX_N][MAX_N];
vector<ii> res;

// For finding cycle
vector<char> color; // 0 for unvisited, 1 for visited, 2 for visited but already exited.
vector<int> par;
int cycle_start, cycle_end;

// For finding strongly connected components
int cnt;
int low[MAX_N], dfn[MAX_N];
bool isRemoved[MAX_N];
stack<int> St;
int nscc; // Number of Strongly Connected Components

bool dfs_color(int u) {
    color[u] = 1;
    for (int v: adj[u]) {
        if (color[v] == 0) {
            par[v] = u;
            if (dfs_color(v))
                return true;
        } else if (color[v] == 1) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
    }
    color[u] = 2;
    return false;
}

void dfs(int u) {
    St.push(u);
    dfn[u] = low[u] = ++cnt;
    for (int v: adj[u]) {
        if (rmEdge == ii(u, v)) continue;
        if (isRemoved[v]) continue;
        if (dfn[v]) {
            low[u] = min(low[u], dfn[v]);
            continue;
        }
        dfs(v);
        low[u] = min(low[u], low[v]);
    }

    if (low[u] == dfn[u]) {
        nscc++;
        while (St.size()) {
            int v = St.top();
            isRemoved[v] = true;
            St.pop();
            if (u == v) break;
        }
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

    // Finding cycle
    color.assign(n + 1, 0);
    par.assign(n + 1, -1);
    cycle_start = -1;

    for (int v = 1; v <= n; v++) {
        if (color[v] == 0 && dfs_color(v))
            break;
    }

    if (cycle_start == -1) {
        cout << "-1\n";
        return 0;
    }

    vector<ii> cycle;
    cycle.push_back({cycle_end, cycle_start});
    for (int v = cycle_end; v != cycle_start; v = par[v])
        cycle.push_back({par[v], v});

    // Finding important arcs
    for (ii e: cycle) {
        if (numArc[e.first][e.second] > 1) continue;
        rmEdge = e, cnt = 0, nscc = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(isRemoved, 0, sizeof(isRemoved));
        for (int u = 1; u <= n; u++)
            if (!dfn[u]) dfs(u);
        if (nscc == n) res.push_back(e);
    }

    // Print out the result
    if (res.empty()) {
        cout << "-1\n";
    } else {
        sort(res.begin(), res.end());
        cout << res.size() << "\n";
        for (ii e: res) cout << e.first << " " << e.second << "\n";
    }
}