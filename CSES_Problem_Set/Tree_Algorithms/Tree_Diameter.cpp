// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005

int n;
int dist[MAX_N];
vector<int> adj[MAX_N];

int farthestVertex(int u) {
    memset(dist, -1, sizeof(dist));
    dist[u] = 0;
    queue<int> Q;
    Q.push(u);

    int ret = 0;
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (int v: adj[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1, ret = v;
            Q.push(v);
        }
    }

    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int u = farthestVertex(1);
    int v = farthestVertex(u);
    cout << dist[v] << "\n";
}