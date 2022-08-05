// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std; 

#define MAX_N 888

int n, m, timer;
vector<int> adj[MAX_N];
int num[MAX_N], low[MAX_N];
bool removed[MAX_N];
stack<int> st;
int nscc = 0;
int inSCC[MAX_N], deg_in[MAX_N];

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

    if (low[u] == num[u]) {
        nscc++;
        int v;
        do {
            inSCC[v = st.top()] = nscc;
            st.pop();
            removed[v] = true;
        } while (v != u);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int u = 1; u <= n; u++)
        if (!num[u]) dfs(u);

    for (int u = 1; u <= n; u++) 
        for (int v: adj[u]) 
            if (inSCC[v] != inSCC[u]) deg_in[inSCC[v]]++;

    int ans = 0;
    for (int u = 1; u <= nscc; u++) ans += !deg_in[u];
    cout << ans << "\n";
}