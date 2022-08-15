// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 40000

int n, m, timer;
bool invalid;
vector<int> adj[MAX_N];
int color[MAX_N], num[MAX_N], low[MAX_N];
bool removed[MAX_N];
stack<int> st;


void set_color(int u, int c) {
    int neg_u = u ^ 1;
    
    if (color[u] == (c ^ 3))
        invalid = true;
    else 
        color[u] = c;

    if (color[neg_u] == c)
        invalid = true;
    else color[neg_u] = c ^ 3;
}

void dfs(int u) {
    num[u] = low[u] = ++timer;
    st.push(u);

    for (int v: adj[u]) {
        if (removed[v]) continue;
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }

        if (color[v] == 1)
            set_color(u, 1);
    }

    if (num[u] == low[u]) {
        if (!color[u])
            set_color(u, 2);
        int v = 0;
        do {
            removed[v = st.top()] = true;
            st.pop();
            set_color(v, color[u]);
        } while (v != u);
    }
}

void add_disjunction(int u, bool nu, int v, bool nv) {
    u = 2 * u ^ nu;
    v = 2 * v ^ nv;
    int neg_u = u ^ 1;
    int neg_v = v ^ 1;
    adj[neg_u].push_back(v);
    adj[neg_v].push_back(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    n <<= 1;
    for (int u = 1; u < n; u += 2) {
        add_disjunction(u, 0, u + 1, 0);
        add_disjunction(u, 1, u + 1, 1);
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        add_disjunction(u, 1, v, 1);
    }

    for (int u = 2; u <= 2 * n + 1; u++)
        if (!num[u]) dfs(u);

    if (invalid) {
        cout << "0\n";
        return 0;
    }
    cout << "1\n";
    for (int u = 1; u <= n; u++)
        if (color[u * 2] == 2) cout << u << " ";
    cout << "\n";
}