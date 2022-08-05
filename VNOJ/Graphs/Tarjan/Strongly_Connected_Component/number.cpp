// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std; 

#define MAX_N 10004

int n, m, t, timer;
vector<int> adj[MAX_N];
int num[MAX_N], low[MAX_N];
bool removed[MAX_N];
int nscc;
stack<int> st;
int inSCC[MAX_N], deg_out[MAX_N];

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

    cin >> n >> m >> t;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int u = 1; u <= n; u++)
        if (!num[u]) dfs(u);

    for (int u = 1; u <= n; u++) 
        for (int v: adj[u]) 
            if (inSCC[v] != inSCC[u]) deg_out[inSCC[u]]++;

    int ans = 0;
    for (int u = 1; u <= nscc; u++)
        ans += !deg_out[u] && u != inSCC[t];
    cout << ans << "\n";
}