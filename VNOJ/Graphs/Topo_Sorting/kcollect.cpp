// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10100

int m, n;
char sq[MAX_N];
int val[MAX_N];
vector<int> adj[MAX_N];

// Convert 1D => 2D
int Id(int i, int j) {
    return (i - 1) * n + j;
}

// Check if a square is in board
bool valid(int i, int j) {
    if (sq[Id(i, j)] == '#') return false;
    return (i && i <= m && j && j <= n);
}

// Tarjan's Algo for finding Strongly Connected Components to compress 
// original graph into DAG.
int timer, nscc;
bool removed[MAX_N];
int num[MAX_N], low[MAX_N];
int total_val[MAX_N], inSCC[MAX_N];
vector<int> adj_scc[MAX_N];
stack<int> st;

void dfs(int u) {
    num[u] = low[u] = ++timer;
    st.push(u);
    for (int v: adj[u]) {
        if (removed[v]) continue;
        if (num[v]) {
            low[u] = min(low[u], num[v]);
            continue;
        }
        dfs(v);
        low[u] = min(low[u], low[v]);
    }

    if (num[u] == low[u]) {
        nscc++;
        int v;
        do {
            inSCC[v = st.top()] = nscc;
            total_val[nscc] += val[v];
            removed[v] = true;
            st.pop();
        } while (v != u);
    }
}

// DP on DAG
int dp[MAX_N];

int calc(int u) {
    if (dp[u] != -1) return dp[u];
    dp[u] = 0;
    for (int v: adj_scc[u])
        dp[u] = max(dp[u], calc(v));
    return (dp[u] += total_val[u]);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    // Input
    cin >> m >> n;
    for (int i = 1; i <= m; i++) 
        for (int j = 1; j <= n; j++) {
            int u = Id(i, j);
            cin >> sq[u];
            val[u] = ('0' <= sq[u] && sq[u] <= '9') ? sq[u] - '0' : 0;
        }

    // Build edges for original graph
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            int u = Id(i, j);
            if (sq[u] == '#') continue;
            if (valid(i, j + 1)) adj[u].push_back(Id(i, j + 1));
            if (valid(i + 1, j)) adj[u].push_back(Id(i + 1, j));
            if (sq[u] == 'W' && valid(i, j - 1)) adj[u].push_back(Id(i, j - 1));
            if (sq[u] == 'N' && valid(i - 1, j)) adj[u].push_back(Id(i - 1, j));
        }

    // Tarjan
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            int u = Id(i, j);
            if (valid(i, j) && !num[u]) dfs(u);
        }

    // Build edges for DAG
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (!valid(i, j)) continue;
            int u = Id(i, j);
            for (int v: adj[u]) 
                if (inSCC[u] != inSCC[v]) adj_scc[inSCC[u]].push_back(inSCC[v]);
        }

    // DP on DAG
    memset(dp, -1, sizeof(dp));
    cout << calc(inSCC[Id(1, 1)]) << "\n";
}