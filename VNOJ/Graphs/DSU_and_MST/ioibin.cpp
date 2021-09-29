// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10004

int q;
int par[MAX_N];

int findRoot(int u) {
    if (par[u] == u)
        return u;
    return par[u] = findRoot(par[u]);
}

void Union(int u, int v) {
    if ((u = findRoot(u)) == (v = findRoot(v))) return;
    par[u] = v;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (int u = 1; u < MAX_N; u++) par[u] = u;
    for (cin >> q; q--;) {
        int u, v, t;
        cin >> u >> v >> t;
        if (t == 1) Union(u, v);
        else cout << (findRoot(u) == findRoot(v)) << "\n";
    }
}