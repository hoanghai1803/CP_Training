// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005
#define oo INT_MAX

int n, q;
int ST[4 * MAX_N];

int update(int id, int L, int R, int p, int v) {
    if (p < L || R < p) return ST[id];
    if (L == R) return (ST[id] = v);
    int M = (L + R) >> 1;
    return (ST[id] = min(update(id * 2, L, M, p, v), update(id * 2 + 1, M + 1, R, p, v)));
}

int getMin(int id, int L, int R, int u, int v) {
    if (v < L || R < u) return +oo;
    if (u <= L && R <= v) return ST[id];
    int M = (L + R) >> 1;
    return min(getMin(id * 2, L, M, u, v), getMin(id * 2 + 1, M + 1, R, u, v));
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (int id = 1; id < 4 * MAX_N; id++) ST[id] = +oo;

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        update(1, 1, n, i, v);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, v;
            cin >> p >> v;
            update(1, 1, n, p, v);
        } else {
            int u, v;
            cin >> u >> v;
            cout << getMin(1, 1, n, u, v) << "\n";
        }
    }
}