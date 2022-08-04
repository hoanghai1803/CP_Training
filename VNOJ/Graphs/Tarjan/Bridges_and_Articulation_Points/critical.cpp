// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 20004

int n, m, timer, sizeCC;
int num[MAX_N], low[MAX_N];
int child[MAX_N], S[MAX_N];
int par[MAX_N];
long long ans = 0;
vector<int> adj[MAX_N];

void dfs(int u) {
    sizeCC++;
    num[u] = low[u] = ++timer;
    for (int v: adj[u]) {
        if (v == par[u]) continue;
        if (num[v]) {
            low[u] = min(low[u], num[v]);
            continue;
        }
        par[v] = u, child[u]++;
        dfs(v);
        low[u] = min(low[u], low[v]);
    }
}

void calc(int u) {
    S[u] = 1;
    int removed = 0;
    for (int v: adj[u]) {
        if (u != par[v]) continue;
        calc(v);
        if (low[v] >= num[u] && (par[u] || child[u] >= 2)) {
            ans += 1LL * S[v] * (sizeCC - S[v] - removed - 1);
            removed += S[v];
        }
        S[u] += S[v];
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

    for (int u = 1; u <= n; u++) {
        if (num[u]) continue;
        timer = 0, sizeCC = 0;
        dfs(u);
        calc(u);
    }
    cout << fixed << setprecision(4) << (double)ans / n << "\n";
}

/*
17 16
1 2
2 3
3 4
2 4
5 7
5 6
8 9
9 10
10 8
11 12
11 13
12 14
14 15
15 16
16 12
16 17

Output: 1.2353
*/