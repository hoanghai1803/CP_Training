// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define oo (int)1e8
#define MAX_N 111

int n;
int s[4];
int dist[MAX_N][MAX_N];

void minimize(int& a, int b) {
    if (a > b) a = b;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // Init
    cin >> n;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            dist[u][v] = (u == v) ? 0 : +oo;

    int u, v, w;
    for (int u = 0; u < 4; u++) cin >> s[u];
    while (cin >> u >> v >> w) {
        minimize(dist[u][v], w);
        minimize(dist[v][u], w);
    }

    // Floyd
    for (int k = 1; k <= n; k++)
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++) 
                minimize(dist[u][v], dist[u][k] + dist[k][v]);

    // Solve
    int res = +oo;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++) {
            int cost = dist[u][s[0]] + dist[u][s[1]] + dist[v][s[2]] + dist[v][s[3]];
            minimize(cost, dist[u][s[0]] + dist[u][s[2]] + dist[v][s[1]] + dist[v][s[3]]);
            minimize(cost, dist[u][s[0]] + dist[u][s[3]] + dist[v][s[1]] + dist[v][s[2]]);
            minimize(res, cost + dist[u][v]);
        }
    cout << res << "\n";
}