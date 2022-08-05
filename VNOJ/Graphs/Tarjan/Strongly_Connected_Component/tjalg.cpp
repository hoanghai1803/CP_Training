// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std; 

#define MAX_N 10004

int n, m, timer, nscc;
vector<int> adj[MAX_N];
int num[MAX_N], low[MAX_N];
bool removed[MAX_N];
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

    if (low[u] == num[u]) {
        nscc++;
        int v;
        do {
            v = st.top();
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
    cout << nscc << "\n";
}