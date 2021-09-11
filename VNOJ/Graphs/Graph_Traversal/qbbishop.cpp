// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

#define MAX_N 222

int n, m;
ii bishop, target;
vector<ii> adj[MAX_N][MAX_N];
bool Free[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

bool Valid(int u, int v) {
    return (u > 0 && u <= n && v > 0 && v <= n && Free[u][v]);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // Input data
    cin >> n >> m;
    cin >> bishop.X >> bishop.Y >> target.X >> target.Y;

    memset(Free, true, sizeof(Free));
    for (int u, v; m--;) {
        cin >> u >> v;
        Free[u][v] = false;
    }

    // Create adjacency list
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++) {
            if (!Free[u][v]) continue;
            bool chk[] = {1, 1, 1, 1};
            int signU[] = {1, -1, 1, -1}, signV[] = {-1, 1, 1, -1};
            for (int k = 1; k < n; k++) {
                for (int t = 0; t < 4; t++) {
                    if (!chk[t]) continue;
                    if (Valid(u + k*signU[t], v + k*signV[t])) 
                        adj[u][v].push_back(ii(u + k*signU[t], v + k*signV[t]));
                    else 
                        chk[t] = false;
                }
            }
        }

    // Init DP array
    memset(dp, -1, sizeof(dp));
    dp[bishop.X][bishop.Y] = 0;

    // Bfs
    queue<ii> Q;
    Q.push(bishop);
    while (Q.size()) {
        int u = Q.front().X, v = Q.front().Y;
        Q.pop();
        for (auto sq: adj[u][v]) {
            if (dp[sq.X][sq.Y] != -1) continue;
            dp[sq.X][sq.Y] = dp[u][v] + 1;
            Q.push(sq);
        }
    }

    cout << dp[target.X][target.Y] << "\n";
}