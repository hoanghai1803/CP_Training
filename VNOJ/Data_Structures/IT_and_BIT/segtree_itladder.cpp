// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define MOD (int)(1e9 + 7)

struct Node {
    int val;
    int lazy[2];
} ST[4 * MAX_N];

void propagation(int id, int L, int R) {
    int M = (L + R) >> 1;
    for (int i = 0; i < 2; i++) {
        int& lz = ST[id].lazy[i];
        for (int j = 0; j < 2; j++) {
            Node& child = ST[id * 2 + j];
            int range = (j == 0 ? M - L + 1 : R - M);
            if (i == 0) {
                int temp = 1LL * (range - 1) * range / 2 % MOD;
                temp = (temp + (j == 0 ? 1LL * L * range : 1LL * (M + 1) * range)) % MOD;
                child.val = (child.val + 1LL * temp * lz) % MOD;
            } else {
                child.val = (child.val + 1LL * lz * range) % MOD;
            }
            child.lazy[i] = (child.lazy[i] + lz) % MOD;
        }
        lz = 0;
    }
}

void update(int id, int L, int R, int u, int v, pair<int, int> q) {
    if (v < L || R < u) return;
    if (u <= L && R <= v)  {
        Node& node = ST[id];
        int a = q.first, b = q.second;
        int range = R - L + 1;

        // Increase (i - u) * A + B, for all i in [L,R]
        int temp_1 = (1LL * (range - 1) * range / 2 % MOD + 1LL * (L - u) * range % MOD) * a % MOD;
        int temp_2 = 1LL * range * b % MOD;
        node.val = ((node.val + temp_1) % MOD + temp_2) % MOD;

        node.lazy[0] = (node.lazy[0] + a) % MOD;
        node.lazy[1] = (node.lazy[1] - 1LL * u * a + b + 1LL * MOD * MOD) % MOD;
        return;
    }

    propagation(id, L, R);
    int M = (L + R) >> 1;
    update(id * 2, L, M, u, v, q);
    update(id * 2 + 1, M + 1, R, u, v, q);
    ST[id].val = (ST[id * 2].val + ST[id * 2 + 1].val) % MOD;
}

int getSum(int id, int L, int R, int u, int v) {
    if (v < L || R < u) return 0;
    if (u <= L && R <= v) return ST[id].val;

    propagation(id, L, R);
    int M = (L + R) >> 1;
    return (getSum(id * 2, L, M, u, v) + getSum(id * 2 + 1, M + 1, R, u, v)) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q;
    for (cin >> n >> q; q--;) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            update(1, 1, n, l, r, {a,  b});
        } else {
            cout << getSum(1, 1, n, l, r) << "\n";
        }
    }
}