// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MAX_N 200005

int n, q, pos = 0;
int val[MAX_N];
int start[MAX_N], finish[MAX_N];
vector<int> adj[MAX_N];
int64 bit[MAX_N];

void update(int p, int v) {
    for (int i = p; i <= n; i += i & -i)
        bit[i] += v;
}

int64 getSum(int p) {
    int64 sum = 0;
    for (int i = p; i; i -= i & -i)
        sum += bit[i];
    return sum;
}

void dfs(int u, int par) {
    start[u] = ++pos;
    update(pos, val[u]);
    for (int v: adj[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
    finish[u] = pos;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q;
    for (int u = 1; u <= n; u++)
        cin >> val[u];

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    while (q--) {
        int id, s, x;
        cin >> id;
        if (id == 1) {
            cin >> s >> x;
            update(start[s], x - val[s]);
            val[s] = x;
        } else {
            cin >> s;
            cout << getSum(finish[s]) - getSum(start[s] - 1) << "\n";
        }
    }
}