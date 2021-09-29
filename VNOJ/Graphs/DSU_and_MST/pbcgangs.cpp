// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1003

int n, m, ncc;
int par[MAX_N];
vector<int> enemies[MAX_N], friends[MAX_N];

int findRoot(int u) {
    if (par[u] == u)
        return u;
    return par[u] = findRoot(par[u]);
}

void Union(int u, int v) {
    if ((u = findRoot(u)) == (v = findRoot(v))) return;
    par[u] = v, ncc--;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    ncc = n;
    for (int u = 1; u <= n; u++) par[u] = u;
    while (m--) {
        char rel;
        int u, v;
        cin >> rel >> u >> v;
        if (rel == 'F') friends[u].push_back(v);
        else {
            enemies[u].push_back(v);
            enemies[v].push_back(u);
        }
    }

    for (int u = 1; u <= n; u++) {
        for (int v: friends[u]) Union(u, v);
        for (int i = 1; i < (int)enemies[u].size(); i++) 
            Union(enemies[u][i - 1], enemies[u][i]);
    }
    cout << ncc << "\n";
}