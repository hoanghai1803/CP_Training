// Author: __BruteForcce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int, int> pii;
typedef pair<int64, pii> plii;

#define MAX_N 100005
#define MAX_K 11

int n, m, k, s, t;
vector<pii> adj[MAX_N];
int64 d[MAX_N][MAX_K];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m >> k >> s >> t;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Dijkstra
    priority_queue<plii, vector<plii>, greater<plii>> Heap;
    memset(d, 0x3f, sizeof(d));
    d[s][0] = 0;
    Heap.push({d[s][0], {s, 0}});
    while (Heap.size()) {
        int64 d_cur = Heap.top().first;
        int u = Heap.top().second.first, tk = Heap.top().second.second;
        Heap.pop();
        if (d_cur != d[u][tk]) continue;

        for (auto [v, w]: adj[u]) {
            if(d[v][tk] > d_cur + w) {
                d[v][tk] = d_cur + w;
                Heap.push({d[v][tk], {v, tk}});
            }
            if (tk < k && d[v][tk + 1] > d_cur) {
                d[v][tk + 1] = d_cur;
                Heap.push({d[v][tk + 1], {v, tk + 1}});
            }
        }
    }

    cout << d[t][k] << "\n";
}