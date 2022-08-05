// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std; 

#define MAX_N 100005

int n, m, timer;
int Next[MAX_N];
int num[MAX_N], low[MAX_N];
bool removed[MAX_N];
stack<int> st;

int nscc = 0;
bool visited[MAX_N];
vector<int> adj[MAX_N];
int inSCC[MAX_N], dp[MAX_N];

void dfs(int u) {
    num[u] = low[u] = ++timer;
    st.push(u);
    int v = Next[u];
    if (!removed[v]) {
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] == num[u]) {
        nscc++;
        int v;
        do {
            inSCC[v = st.top()] = nscc;
            dp[nscc]++;
            st.pop();
            removed[v] = true;
        } while (v != u);
    }
}

void Visit(int u) {
    visited[u] = true;
    for (int v: adj[u]) {
        if (!visited[v]) Visit(v);
        dp[u] += dp[v];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int u = 1; u <= n; u++)
        cin >> Next[u];

    for (int u = 1; u <= n; u++)
        if (!num[u]) dfs(u);

    for (int u = 1; u <= n; u++) 
        if (inSCC[u] != inSCC[Next[u]])
            adj[inSCC[u]].push_back(inSCC[Next[u]]);

    for (int u = 1; u <= nscc; u++)
        if (!visited[u]) Visit(u);
    
    for (int u = 1; u <= n; u++)
        cout << dp[inSCC[u]] << "\n";
}