// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define MAX_N 50004

struct Node {
    int lazy, val;
} st[4 * MAX_N];

void propagate(int id) {
    int& t = st[id].lazy;
    st[id << 1].lazy += t, st[id << 1].val += t;
    st[id << 1 | 1].lazy += t, st[id << 1 | 1].val += t;
    t = 0;
}

void update(int id, int L, int R, int u, int v, int val) {
    if (v < L || R < u) return;
    if (u <= L && R <= v) {
        st[id].val += val, st[id].lazy += val;
        return;
    }

    propagate(id);
    int M = L + R >> 1;
    update(id << 1, L, M, u, v, val);
    update(id << 1 | 1, M + 1, R, u, v, val);
    st[id].val = max(st[id << 1].val, st[id << 1 | 1].val);
}

int get_max(int id, int L, int R, int u, int v) {
    if (v < L || R < u) return -oo;
    if (u <= L && R <= v) return st[id].val;

    propagate(id);
    int M = L + R >> 1;
    return max(get_max(id << 1, L, M, u, v),
               get_max(id << 1 | 1, M + 1, R, u, v));
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int id, x, y, v;
    while (m--) {
        cin >> id;
        if (!id) {
            cin >> x >> y >> v;
            update(1, 1, n, x, y, v);
        } else {
            cin >> x >> y;
            cout << get_max(1, 1, n, x, y) << "\n";
        }
    }
}