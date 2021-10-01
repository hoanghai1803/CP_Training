// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64; 
typedef pair<int64, int64> ii;

#define oo INT_MAX
#define MAX_N 5555

int n, m;
vector<ii> adj[MAX_N];
int64 d[MAX_N], cnt[MAX_N];

void Dijkstra() {
    d[1] = 0, cnt[1] = 1;
    for (int u = 2; u <= n; u++) d[u] = +oo;

    priority_queue<ii, vector<ii>, greater<ii>> Heap;
    Heap.push({d[1], 1});
    while (Heap.size()) {
        int64 du = Heap.top().first, u = Heap.top().second;
        Heap.pop();
        if (du != d[u]) continue;
        if (u == n) break;
        for (auto e: adj[u]) {
            int64 v = e.first, l = e.second;
            if (d[v] == d[u] + l) cnt[v] += cnt[u];
            if (d[v] > d[u] + l) {
                d[v] = d[u] + l, cnt[v] = cnt[u];
                Heap.push({d[v], v});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> n >> m;
    for (int k, u, v, l; m--;) {
        cin >> k >> u >> v >> l;
        adj[u].push_back({v, l});
        if (k == 2) adj[v].push_back({u, l});
    }

    Dijkstra();
    cout << d[n] << " " << cnt[n] << "\n";
}