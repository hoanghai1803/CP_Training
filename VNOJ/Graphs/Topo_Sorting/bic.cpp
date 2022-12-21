// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10004
#define MOD (int)(1e9)

int n, m;
int valid_vtx;
bool visited[2][MAX_N], overflow[MAX_N];
int deg_in[MAX_N], dp[MAX_N];
vector<int> adj[2][MAX_N]; // 0 for adjacency list, 1 for reverse adjacency list
vector<int> topo;

void bfs(int idx, int src) {
    queue<int> Q;
    Q.push(src);
    visited[idx][src] = true;
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (int v: adj[idx][u]) {
            if (visited[idx][v]) continue;
            visited[idx][v] = true;
            Q.push(v);
        }
    }
}

bool valid(int u) {
    return visited[0][u] & visited[1][u];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
        deg_in[v]++;
    }

    bfs(0, 1); 
    bfs(1, 2);
    for (int u = 1; u <= n; u++) {
        if (valid(u)) {
            valid_vtx++;
            continue;
        }
        for (int v: adj[0][u]) deg_in[v]--;
    }

    queue<int> Q;
    for (int u = 1; u <= n; u++)
        if (!deg_in[u] && valid(u)) Q.push(u);

    dp[1] = 1;
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        topo.push_back(u); 
        for (int v: adj[0][u]) {
            if (!valid(v)) continue;
            overflow[v] |= dp[u] + dp[v] >= MOD || overflow[u];
            dp[v] = (dp[u] + dp[v]) % MOD;
            if (!--deg_in[v]) Q.push(v);
        }
    }

    if ((int)topo.size() < valid_vtx) {
        cout << "inf\n"; // Graph contains a cycle
        return 0;
    }

    if (overflow[2]) cout << setw(9) << setfill('0') << dp[2] << "\n";
    else cout << dp[2] << "\n";
}