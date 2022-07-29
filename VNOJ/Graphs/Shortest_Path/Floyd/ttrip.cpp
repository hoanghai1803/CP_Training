// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define oo (int)(1e9)
#define MAX_N 111

int n;
int c[MAX_N][MAX_N], visited[MAX_N];
priority_queue<pii, vector<pii>, greater<pii>> adj[MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // Input
    cin >> n;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++) {
            cin >> c[u][v];
            if (!c[u][v]) c[u][v] = +oo;
        }

    // Floyd
    for (int k = 1; k <= n; k++)
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++) 
                c[u][v] = min(c[u][v], c[u][k] + c[k][v]);

    for (int u = 1; u <= n; u++) 
        for (int v = 1; v < n; v++) 
            adj[u].push({c[u][v], v});

    long long ans = 0;
    int u = 1; 
    while (1) {
        visited[u] = true;
        while (adj[u].size() && visited[adj[u].top().second])
            adj[u].pop();
        if (adj[u].empty()) {
            ans += c[u][n];
            break;
        } else {
            int v = adj[u].top().second;
            ans += adj[u].top().first;
            adj[u].pop();
            u = v;
        }
    }
    cout << ans << "\n";
}