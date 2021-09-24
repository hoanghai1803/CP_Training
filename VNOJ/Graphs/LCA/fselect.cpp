// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005
#define LOG_N 22

int n, k, root;
vector<int> mt[MAX_N], adj[MAX_N];
int depth[MAX_N], Par[LOG_N + 1][MAX_N];

void dfs(int u) {
    for (int v: adj[u]) {
        depth[v] = depth[u] + 1;
        Par[0][v] = u;
        dfs(v);
    }
}

int Calc(int u, int v) {
    int ret = 0;
    if (depth[u] < depth[v]) swap(u, v);

    for (int k = LOG_N; k >= 0; k--)
        if (depth[Par[k][u]] >= depth[v]) {
            u = Par[k][u]; 
            ret += 1 << k;
        }
    if (u == v) return ret;

    for (int k = LOG_N; k >= 0; k--)
        if (Par[k][u] != Par[k][v]) {
            u = Par[k][u], v = Par[k][v];
            ret += 1 << (k + 1);
        }
    return ret + 2;
}

int findFurthest(int u, vector<int> mt) {
    int ret = u, curr = 0, dist = 0;
    for (int v: mt) 
        if ((dist = Calc(u, v)) > curr) ret = v, curr = dist;
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k;
    for (int u = 1; u <= n; u++) {
        int meeting, pa;
        cin >> meeting >> pa;
        mt[meeting].push_back(u);
        if (pa) adj[pa].push_back(u);
        else root = u;
    }

    depth[root] = 1;
    dfs(root);

    for (int k = 1; k <= LOG_N; k++) 
        for (int u = 1; u <= n; u++) 
            Par[k][u] = Par[k - 1][Par[k - 1][u]];

    for (int i = 1; i <= k; i++) {
        int u = findFurthest(mt[i][0], mt[i]);
        int v = findFurthest(u, mt[i]);
        cout << Calc(u, v) << "\n";
    }
}