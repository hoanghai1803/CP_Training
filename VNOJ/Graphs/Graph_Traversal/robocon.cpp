// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

#define MAX_N 555

int dx[2][3] = {{0, 1, 1}, {0, 1, 1}};
int dy[2][3] = {{1, 0, 1}, {-1, 0, -1}};

int n, k;
bool Free[MAX_N][MAX_N];
bool Avail[2][MAX_N][MAX_N];
vector<ii> border[2], temp[2];

bool Valid(int u, int v) {
    return (u && u <= n && v && v <= n && Free[u][v]);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k;
    memset(Free, true, sizeof(Free));
    memset(Avail, true, sizeof(Avail));
    border[0].push_back(ii(1, 1));
    border[1].push_back(ii(1, n));

    for (int u, v; k--;) {            
        cin >> u >> v;
        Free[u][v] = false;
    }

    for (int steps = 1; ; steps++) {
        for (int rb = 0; rb < 2; rb++) {
            for (ii sq: border[rb]) 
                for (int d = 0; d < 3; d++) {
                    int u = sq.X + dx[rb][d];
                    int v = sq.Y + dy[rb][d];
                    if (!Valid(u, v)) continue;
                    if (!Avail[0][u][v]) {
                        if (!rb) continue;
                        cout << steps << "\n";
                        return 0;
                    }
                    if (Avail[rb][u][v]) {
                        temp[rb].push_back(ii(u, v));
                        Avail[rb][u][v] = false;
                    }
                }
            border[rb] = temp[rb], temp[rb].clear();
        }
        for (int rb = 0; rb < 2; rb++)
            for (ii sq: border[rb]) Avail[rb][sq.X][sq.Y] = true;
    }
}
