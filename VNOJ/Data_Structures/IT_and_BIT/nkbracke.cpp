// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define MAX_N 100005

struct Node {
    int sum, min, lazy;
} st[4 * MAX_N];

void propagate(int id, int L, int R) {
    int& t = st[id].lazy;
    int M = L + R >> 1;
    int l_node = id << 1, r_node = id << 1 | 1;

    if (L == M) st[l_node].sum += t;
    st[l_node].min += t, st[l_node].lazy += t;
    if (M + 1 == R) st[r_node].sum += t;
    st[r_node].min += t, st[r_node].lazy += t;
    t = 0;
}

void update(int id, int L, int R, int p, int sign) {
    if (R < p) return;
    if (L == R) st[id].sum += sign;
    if (L >= p) {
        st[id].min += sign, st[id].lazy += sign;
        return;
    }

    propagate(id, L, R);
    int M = L + R >> 1;
    update(id << 1, L, M, p, sign);
    update(id << 1 | 1, M + 1, R, p, sign);
    st[id].min = min(st[id << 1].min, st[id << 1 | 1].min);
}

int get_sum(int id, int L, int R, int p) {
    if (!p || p < L || R < p) return 0;
    if (L == R) return st[id].sum;

    propagate(id, L, R);
    int M = L + R >> 1;
    return (p <= M) ? get_sum(id << 1, L, M, p)
                    : get_sum(id << 1 | 1, M + 1, R, p);
}

int get_min(int id, int L, int R, int u, int v) {
    if (v < L || R < u) return +oo;
    if (u <= L && R <= v) return st[id].min;

    propagate(id, L, R);
    int M = L + R >> 1;
    return min(get_min(id << 1, L, M, u, v),
               get_min(id << 1 | 1, M + 1, R, u, v));
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    auto check_br = [&](int L, int R) {
        if (get_sum(1, 1, n, R) - get_sum(1, 1, n, L - 1) != 0) return 0;
        if (get_min(1, 1, n, L, R) - get_sum(1, 1, n, L - 1) < 0) return 0;
        return 1;
    };

    string s;
    cin >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = (s[i - 1] == '(') ? 1 : -1;
        update(1, 1, n, i, a[i]);
    }

    int id, i, j;
    char ch;
    while (m--) {
        cin >> id;
        if (!id) {
            cin >> i >> ch;
            int sign = (ch == '(') ? 1 : -1;
            update(1, 1, n, i, sign - a[i]);
            a[i] = sign;
        } else {
            cin >> i >> j;
            cout << check_br(i, j);
        }
    }
}