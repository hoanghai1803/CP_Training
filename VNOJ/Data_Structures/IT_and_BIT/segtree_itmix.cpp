// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define MOD (int)(1e9 + 7)

struct Node {
    int sum;
    int lazy[2];
} ST[4 * MAX_N];

void propagation(int id, int L, int R) {
    int M = (L + R) >> 1;
    int range[] = {M - L + 1, R - M};
    int& lz_0 = ST[id].lazy[0];
    int& lz_1 = ST[id].lazy[1];

    for (int k = 0; k < 2; k++) {
        Node& child = ST[id * 2 + k];
        child.sum = 1LL * child.sum * lz_1 % MOD;
        child.sum = (child.sum + 1LL * lz_0 * range[k]) % MOD;
        child.lazy[0] = (1LL * child.lazy[0] * lz_1 + lz_0) % MOD;
        child.lazy[1] = 1LL * child.lazy[1] * lz_1 % MOD;
    }
    
    lz_0 = 0, lz_1 = 1;
}

void update(int tp, int id, int L, int R, int u, int v, int val) {
    if (v < L || R < u) return;
    if (u <= L && R <= v) {
        Node& node = ST[id];
        int range = R - L + 1;
        if (tp == 0) {
            node.sum = (node.sum + 1LL * range * val) % MOD;
            node.lazy[0] = (node.lazy[0] + val) % MOD;
        } else {
            node.sum = 1LL * node.sum * val % MOD;
            node.lazy[0] = 1LL * node.lazy[0] * val % MOD;
            node.lazy[1] = 1LL * node.lazy[1] * val % MOD;
        }
        return;
    }

    propagation(id, L, R);
    int M = (L + R) >> 1;
    update(tp, id * 2, L, M , u, v, val);
    update(tp, id * 2 + 1, M + 1, R, u, v, val);
    ST[id].sum = (ST[id * 2].sum + ST[id * 2 + 1].sum) % MOD;
}

int getSum(int id, int L, int R, int u, int v) {
    if (v < L || u > R) return 0;
    if (u <= L && v >= R) return ST[id].sum;

    propagation(id, L, R);
    int M = (L + R) >> 1;
    return (getSum(id * 2, L, M, u, v) + getSum(id * 2 + 1, M + 1, R, u, v)) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (int i = 1; i < 4 * MAX_N; i++)
        ST[i].lazy[1] = 1;

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        update(0, 1, 1, n, i, i, val);
    }

    while (q--) {
        int type, l, r, x;
        cin >> type >> l >> r;

        if (type == 4) {
            cout << getSum(1, 1, n, l, r) << "\n";
            continue;
        }

        cin >> x;
        if (type == 1) {
            update(0, 1, 1, n, l, r, x);
        } else if (type == 2) {
            update(1, 1, 1, n, l, r, x);
        } else {
            update(1, 1, 1, n, l, r, 0);
            update(0, 1, 1, n, l, r, x);
        }
    }
}