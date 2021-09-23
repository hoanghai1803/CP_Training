// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define MAX_N 100005
#define LOG_N 22

int n, q;
vector<pair<int, int>> adj[MAX_N];
int depth[MAX_N];
int minPath[LOG_N + 1][MAX_N], maxPath[LOG_N + 1][MAX_N];
int Par[LOG_N + 1][MAX_N];

void minimize(int& target, int val1, int val2 = +oo) {
    target = min(target, min(val1, val2));
}

void maximize(int& target, int val1, int val2 = 0) {
    target = max(target, max(val1, val2));
}

void dfs(int u) {
    for (auto child: adj[u]) {
        int v = child.first, l = child.second;
        if (v == Par[0][u]) continue;
        depth[v] = depth[u] + 1;
        minPath[0][v] = maxPath[0][v] = l;
        Par[0][v] = u;
        dfs(v);
    }
}

void Calc(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int d_min = +oo, d_max = 0;

    for (int k = LOG_N; k >= 0; k--)
        if (depth[Par[k][u]] >= depth[v]) {
            minimize(d_min, minPath[k][u]);
            maximize(d_max, maxPath[k][u]);
            u = Par[k][u];
        }

    if (u == v) {
        cout << d_min << " " << d_max << "\n";
        return;
    }

    for (int k = LOG_N; k >= 0; k--) 
        if (Par[k][u] != Par[k][v]) {
            minimize(d_min, minPath[k][u], minPath[k][v]);
            maximize(d_max, maxPath[k][u], maxPath[k][v]);
            u = Par[k][u], v = Par[k][v];
        }

    minimize(d_min, minPath[0][u], minPath[0][v]);
    maximize(d_max, maxPath[0][u], maxPath[0][v]);
    cout << d_min << " " << d_max << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }

    depth[1] = 1;
    dfs(1);
    for (int k = 1; k <= LOG_N; k++)
        for (int u = 1; u <= n; u++) {
            minPath[k][u] = min(minPath[k - 1][u], minPath[k - 1][Par[k - 1][u]]);
            maxPath[k][u] = max(maxPath[k - 1][u], maxPath[k - 1][Par[k - 1][u]]);
            Par[k][u] = Par[k - 1][Par[k - 1][u]];
        }

    for (cin >> q; q--;) {
        int u, v;
        cin >> u >> v;
        Calc(u, v);
    }
}