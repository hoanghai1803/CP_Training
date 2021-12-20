// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define oo LLONG_MAX
#define MAX_N 100005

struct Node {
    int64 maxVal, lazy;
} ST[4 * MAX_N];

void Propagation(int id) {
    int64 lz = ST[id].lazy;
    ST[id * 2].maxVal += lz, ST[id * 2].lazy += lz;
    ST[id * 2 + 1].maxVal += lz, ST[id * 2 + 1].lazy += lz;
    ST[id].lazy = 0;
}

int64 Update(int id, int L, int R, int u, int v, int val) {
    if (v < L || R < u)
        return ST[id].maxVal;
    if (u <= L && R <= v)  {
        ST[id].maxVal += val, ST[id].lazy += val;
        return ST[id].maxVal;
    }

    Propagation(id);
    int M = (L + R) >> 1;
    return (ST[id].maxVal = max(Update(id * 2, L, M, u, v, val), Update(id * 2 + 1, M + 1, R, u, v, val)));
}

int64 Get(int id, int L, int R, int u, int v) {
    if (v < L || R < u) 
        return -oo;
    if (u <= L && R <= v) 
        return ST[id].maxVal;

    Propagation(id);
    int M = (L + R) >> 1;
    return max(Get(id * 2, L, M, u, v), Get(id * 2 + 1, M + 1, R, u, v));
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q, val;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        Update(1, 1, n, i, i, val);
    }

    for (cin >> q; q--;) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            int val;
            cin >> val;
            Update(1, 1, n, l, r, val);
        } else {
            cout << Get(1, 1, n, l, r) << "\n";
        }
    }
}