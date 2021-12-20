// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define oo INT_MAX

int n, q;
int arr[MAX_N];
multiset<int> ST[4 * MAX_N];

void build(int id, int L, int R) {
    if (L == R) {
        ST[id].insert(arr[L]);
        return;
    }

    int M = (L + R) >> 1;
    build(id * 2, L, M);
    build(id * 2 + 1, M + 1, R);
    for (int tmp = 0; tmp < 2; tmp++)
        for (auto v: ST[id * 2 + tmp]) ST[id].insert(v);
}

void update(int id, int L, int R, int p, int v) {
    if (p < L || R < p) return;
    ST[id].erase(ST[id].find(arr[p]));
    ST[id].insert(v);
    if (L == R) return;

    int M = (L + R) >> 1;
    update(id * 2, L, M, p, v);
    update(id * 2 + 1, M + 1, R, p, v);
}

int getMin(int id, int L, int R, int u, int v, int k) {
    if (v < L || R < u) return +oo;
    if (u <= L && R <= v) {
        auto pos = ST[id].lower_bound(k);
        if (pos != ST[id].end()) return *pos;
        return +oo;
    }

    int M = (L + R) >> 1;
    return min(getMin(id * 2, L, M, u, v, k), getMin(id * 2 + 1, M + 1, R, u, v, k));
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) 
        cin >> arr[i];
    build(1, 1, n);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, v;
            cin >> p >> v;
            update(1, 1, n, p, v);
            arr[p] = v;
        } else {
            int u, v, k;
            cin >> u >> v >> k;
            int minVal = getMin(1, 1, n, u, v, k);
            cout << (minVal == +oo ? -1 : minVal) << "\n";
        }
    }
}