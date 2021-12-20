// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define oo INT_MAX

int n, q;
int ST[4 * MAX_N];

int update(int id, int L, int R, int p, int v) {
    if (p < L || R < p) return ST[id];
    if (L == R) return (ST[id] = v);
    int M = (L + R) >> 1;
    return (ST[id] = max(update(id * 2, L, M, p, v), update(id * 2 + 1, M + 1, R, p, v)));
}

int getMax(int id, int L, int R, int u, int v) {
    if (v < L || R < u) return -oo;
    if (u <= L && R <= v) return ST[id];
    int M = (L + R) >> 1;
    return max(getMax(id * 2, L, M, u, v), getMax(id * 2 + 1, M + 1, R, u, v));
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (int id = 1; id < 4 * MAX_N; id++) ST[id] = -oo;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        update(1, 1, n, i, v);
    }

    for (cin >> q; q--;) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, v;
            cin >> p >> v;
            update(1, 1, n, p, v);
        } else {
            int u, v;
            cin >> u >> v;
            cout << getMax(1, 1, n, u, v) << "\n";
        }
    }
}