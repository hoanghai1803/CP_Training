// Author: BruteForce - Problem B
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

struct Node {
    long long sum, lazy;
} Nodes[4 * MAX_N];

void Propagation(int id, int L, int R) {
    long long lz = Nodes[id].lazy;
    int M = (L + R) >> 1;
    Nodes[id * 2].sum += lz * (M - L + 1), Nodes[id * 2].lazy += lz;
    Nodes[id * 2 + 1].sum += lz * (R - M), Nodes[id * 2 + 1].lazy += lz;
    Nodes[id].lazy = 0;
}

long long Update(int id, int L, int R, int u, int v, int val) {
    if (v < L || R < u)
        return Nodes[id].sum;
    if (u <= L && R <= v)  {
        Nodes[id].sum += 1LL * val * (R - L + 1), Nodes[id].lazy += val;
        return Nodes[id].sum;
    }

    Propagation(id, L, R);
    int M = (L + R) >> 1;
    return (Nodes[id].sum = Update(id * 2, L, M, u, v, val) + Update(id * 2 + 1, M + 1, R, u, v, val));
}

long long Get(int id, int L, int R, int u, int v) {
    if (v < L || R < u) 
        return 0;
    if (u <= L && R <= v) 
        return Nodes[id].sum;

    Propagation(id, L, R);
    int M = (L + R) >> 1;
    return Get(id * 2, L, M, u, v) + Get(id * 2 + 1, M + 1, R, u, v);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q, val;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        Update(1, 1, n, i, i, val);
    }
    
    while (q--) {
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