// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define oo LLONG_MAX
#define MAX_N 100005

int n, s;
vector<pair<int, int>> adj[MAX_N];
int64 dp_up[MAX_N], dp_down[MAX_N];
int64 ans = +oo;

template <class X> 
void maximize(X& num, X val) {
    num = max(num, val);
}

template <class X>
void minimize(X& num, X val) {
    num = min(num, val);
}

void calc_down(int u, int par) {
    for (auto [v, c]: adj[u]) {
        if (v == par) continue;
        calc_down(v, u);
        maximize(dp_down[u], dp_down[v] + c);
    }
}

void calc_up(int u, int par) {
    int64 max_len = -oo, secMax_len = -oo;
    for (auto [v, c]: adj[u]) {
        if (v == par) continue;
        int64 new_len = dp_down[v] + c;
        if (new_len >= max_len)
            secMax_len = max_len, max_len = new_len;
        else if (new_len > secMax_len)
            secMax_len = new_len;
    }

    for (auto [v, c]: adj[u]) {
        if (v == par) continue;
        int64 longest_path = (max_len == dp_down[v] + c) ? secMax_len : max_len;
        dp_up[v] = max(dp_up[u], longest_path) + c;
        calc_up(v, u);
    }
}

void dfs(int u, int par) {
    minimize(ans, max(dp_up[u], dp_down[u]));
    for (auto [v, c]: adj[u]) {
        if (v == par) continue;
        if (c <= s) minimize(ans, max(dp_down[v], dp_up[v] - c));
        dfs(v, u);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    calc_down(1, 0);
    calc_up(1, 0);
    dfs(1, 0);
    cout << ans << "\n";
}