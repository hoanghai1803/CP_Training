// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define MAX_N 50004

struct Node {
    int lazy, val;
} st[4 * MAX_N];

void propagate(int id, int L, int R) {
    if (!st[id].lazy) return;
    st[id].lazy = 0;

    int M = L + R >> 1;
    int l_node = id << 1, r_node = id << 1 | 1;
    st[l_node].val = M - L + 1 - st[l_node].val;
    st[l_node].lazy = (st[l_node].lazy + 1) % 2;
    st[r_node].val = R - M - st[r_node].val;
    st[r_node].lazy = (st[r_node].lazy + 1) % 2;
}

void update(int id, int L, int R, int u, int v) {
    if (v < L || R < u) return;
    if (u <= L && R <= v) {
        st[id].val = R - L + 1 - st[id].val;
        st[id].lazy = (st[id].lazy + 1) % 2;
        return;
    }

    propagate(id, L, R);
    int M = L + R >> 1;
    update(id << 1, L, M, u, v);
    update(id << 1 | 1, M + 1, R, u, v);
    st[id].val = st[id << 1].val + st[id << 1 | 1].val;
}

int get(int id, int L, int R, int u, int v) {
    if (v < L || R < u) return 0;
    if (u <= L && R <= v) return st[id].val;

    propagate(id, L, R);
    int M = L + R >> 1;
    return get(id << 1, L, M, u, v) + get(id << 1 | 1, M + 1, R, u, v);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int id, l, r;
    while (m--) {
        cin >> id >> l >> r;
        if (!id)
            update(1, 1, n, l, r);
        else
            cout << get(1, 1, n, l, r) << "\n";
    }
}