// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define MAX_N 777

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int n, m;
int h[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

bool Valid(int u, int v) {
    return (u && u <= n && v && v <= m);
}

bool Bfs(int u, int v) {
    int height = h[u][v];
    bool isHilltop = true;

    queue<ii> Q;
    Q.push(ii(u, v));
    while (Q.size()) {
        u = Q.front().first, v = Q.front().second;
        Q.pop();
        for (int d = 0; d < 8; d++) {
            int _u = u + dx[d], _v = v + dy[d];
            if (!Valid(_u, _v)) continue;

            isHilltop &= (height >= h[_u][_v]);
            if (h[_u][_v] == h[u][v] && !visited[_u][_v])
                Q.push(ii(_u, _v)), visited[_u][_v] = true;
        }
    }

    return isHilltop;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= m; v++)
            cin >> h[u][v];

    int res = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= m; v++)
            if (!visited[u][v]) res += Bfs(u, v);
    cout << res << "\n";
}
