// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int64, int> pli;

#define MAX_N 100005
#define MAX_M 100005

struct Edge {
    int to_vtx;
    int w;
    vector<int> adj;
};

int n, m, s, t, delta;
Edge e[MAX_M];
vector<int> edge_in[MAX_N], edge_out[MAX_N];
int64 d[MAX_M];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m >> s >> t >> delta;
    e[0].to_vtx = s;
    edge_in[s].push_back(0);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i].to_vtx = v, e[i].w = w;
        edge_out[u].push_back(i);
        edge_in[v].push_back(i);
        for (int idx: edge_in[u]) e[idx].adj.push_back(i);
        for (int idx: edge_out[v]) e[i].adj.push_back(idx);
    }
    
    // Dijkstra
    priority_queue<pli, vector<pli>, greater<pli>> Heap;
    memset(d, 0x3f, sizeof(d));
    d[0] = 0;
    Heap.push({d[0], 0});
    while (Heap.size()) {
        int64 d_cur = Heap.top().first;
        int idx = Heap.top().second;
        Heap.pop();
        if (d_cur != d[idx]) continue;
        if (e[idx].to_vtx == t) {
            cout << d_cur << "\n";
            return 0;
        }
        for (int i: e[idx].adj) {
            int64 new_cost = d_cur + e[i].w + 1LL * idx * delta + i;
            if (!idx) new_cost -= i;
            if (d[i] > new_cost) {
                d[i] = new_cost;
                Heap.push({d[i], i});
            }
        }
    }

    cout << "-1\n";
}