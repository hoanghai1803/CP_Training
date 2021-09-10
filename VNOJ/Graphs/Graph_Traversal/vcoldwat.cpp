// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

int n, c;
pair<int, int> Children[MAX_N];
int dist[MAX_N];

void dfs(int u) {
    int Child_ST = Children[u].first, Child_ND = Children[u].second;
    if (!Child_ST) return;

    dist[Child_ST] = dist[Child_ND] = dist[u] + 1;
    dfs(Child_ST), dfs(Child_ND);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> c;
    int e, u, v;
    while (c--) {
        cin >> e >> u >> v;
        Children[e] = make_pair(u, v);
    }
    dist[1] = 1;

    dfs(1);
    for (int u = 1; u <= n; u++)
        cout << dist[u] << "\n";
}
