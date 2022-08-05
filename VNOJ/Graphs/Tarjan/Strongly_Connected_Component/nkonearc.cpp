// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std; 

#define MAX_N 2222
int n, m, timer;

vector<int> adj[MAX_N];
int num[MAX_N], low[MAX_N];
bool removed[MAX_N];
stack<int> st;
int nscc = 0;
int inSCC[MAX_N], deg_in[MAX_N], deg_out[MAX_N];

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
        for (int v: adj[u]) {
            if (inSCC[v] == inSCC[u]) continue;
            deg_in[inSCC[v]]++;
            deg_out[inSCC[u]]++;
        }

    int cnt1 = 0, cnt2 = 0;
    int begin_scc = 0,end_scc = 0;
    for (int u = 1; u <= nscc; u++) {
        if (!deg_in[u]) begin_scc = u, cnt1++;
        if (!deg_out[u]) end_scc = u, cnt2++;
    }
    if (cnt1 > 1 || cnt2 > 1) {
        cout << "NO\n";
        return 0;
    }
        
    cout << "YES\n";
    for (int u = 1; u <= n; u++)
        if (inSCC[u] == end_scc) {
            cout << u << " ";
            break;
        }
    for (int u = 1; u <= n; u++)
        if (inSCC[u] == begin_scc) {
            cout << u << "\n";
            break;
        }
}