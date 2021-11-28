// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005

int n;
int children[MAX_N];
vector<int> adj[MAX_N];

void dfs(int u) {
    for (int v: adj[u]) {
        dfs(v);
        children[u] += children[v] + 1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int u = 2, boss; u <= n; u++) {
        cin >> boss;
        adj[boss].push_back(u);
    }

    dfs(1);
    for (int u = 1; u <= n; u++)
        cout << children[u] << " ";
}