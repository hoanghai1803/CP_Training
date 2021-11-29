#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005

int n;
int dist[2][MAX_N];
vector<int> adj[MAX_N];

int farthestVertex(int src, int id = 0) {
    memset(dist[id], -1, sizeof(dist[id]));
    dist[id][src] = 0;
    queue<int> Q;
    Q.push(src);

    int ret = src;
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (int v: adj[u]) {
            if (dist[id][v] != -1) continue;
            dist[id][v] = dist[id][u] + 1;
            ret = v;
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
    int v = farthestVertex(u, 0);
    farthestVertex(v, 1);

    for (int u = 1; u <= n; u++) 
        cout << max(dist[0][u], dist[1][u]) << " ";
    cout << "\n";
}