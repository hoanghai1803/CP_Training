// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define MAX_N 111

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n;
int h[MAX_N][MAX_N];
bool Visited[MAX_N][MAX_N], Valid[MAX_N][MAX_N];

bool Bfs() {
    memset(Visited, false, sizeof(Visited));
    queue<ii> Q;
    Q.push(ii(1, 1));

    while(Q.size()) {
        int u = Q.front().first, v = Q.front().second;
        Q.pop();
        for (int d = 0; d < 4; d++) {
            int _u = u + dx[d], _v = v + dy[d];
            if (Valid[_u][_v] && !Visited[_u][_v]) {
                if (_u == n && _v == n) return true;
                Q.push(ii(_u, _v));
                Visited[_u][_v] = true;
            }
        }
    }
    
    return false;
}

bool Check(int d) {
    for (int k = max(h[1][1] - d, 0); k <= 110 - d; k++) {
        if (h[1][1] < k) break;
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
                Valid[u][v] = (h[u][v] >= k && h[u][v] <= k + d);
        if (Bfs()) return true;
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            cin >> h[u][v];

    // Binary Search for the height difference
    for (int L = 0, R = 110; ;) {
        int M = (L + R) >> 1;
        if (M == L || M == R) {
            cout << (Check(L) ? L : R) << "\n";
            break;
        }

        if (Check(M)) R = M;
        else L = M;
    }
}
