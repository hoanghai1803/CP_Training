// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define oo (int64)(1e15)
#define MAX_N 555

int n, m, k;
int64 c[MAX_N][MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) c[u][v] = +oo;
        c[u][u] = 0;
    }

    for (int u, v; m--;) {
        cin >> u >> v;
        cin >> c[u][v];
    }

    for (int id, x, y; k--;) {
        cin >> id;
        if (id == 1) {
            cin >> x;
            for (int u = 1; u <= n; u++)
                for (int v = 1; v <= n; v++)
                    c[u][v] = min(c[u][v], c[u][x] + c[x][v]);
        } else {
            cin >> x >> y;
            if (c[x][y] == +oo) cout << "-1\n";
            else cout << c[x][y] << "\n";
        }
    }
}