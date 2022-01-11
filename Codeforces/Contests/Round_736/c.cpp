#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005

int n, m, q;
set<int> adj[MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int res = n;
    for (int u = 1; u <= n; u++) 
        if (adj[u].size() && u < *adj[u].rbegin()) 
            res--;

    cin >> q;
    while (q--) {
        int id;
        cin >> id;
        if (id == 3) 
            cout << res << "\n";

        if (id == 1) {
            int u, v;
            cin >> u >> v;
            if (u < v)
                swap(u, v);
            if (!adj[v].size() || (adj[v].size() && v > *adj[v].rbegin())) 
                res--;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        if (id == 2) {
            int u, v;
            cin >> u >> v;
            if (u < v)
                swap(u, v);
            adj[u].erase(v);
            adj[v].erase(u);
            if (!adj[v].size() || v > *adj[v].rbegin())
                res++;
        }
    }
}