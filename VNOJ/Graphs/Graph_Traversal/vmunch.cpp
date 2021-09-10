// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

#define MAX_N 111

int m, n;
char sq;
ii byre;
bool Valid[MAX_N][MAX_N], Visited[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
queue<ii> Q;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> m >> n;
    for (int u = 1; u <= m; u++)
        for (int v = 1; v <= n; v++) {
            cin >> sq;
            Valid[u][v] = (sq == '.' || sq == 'B');
            if (sq == 'B') byre = ii(u, v);
            if (sq == 'C') Q.push(ii(u, v));
        }

    // Bfs
    while (Q.size()) {
        int u = Q.front().first, v = Q.front().second;
        Q.pop();
        for (int d = 0; d < 4; d++) {
            int _u = u + dx[d], _v = v + dy[d];
            if (Valid[_u][_v] && !Visited[_u][_v]) {
                Visited[_u][_v] = true;
                dp[_u][_v] = dp[u][v] + 1;
                Q.push(ii(_u, _v));
            }
        }
    }

    cout << dp[byre.first][byre.second] << "\n";
}
