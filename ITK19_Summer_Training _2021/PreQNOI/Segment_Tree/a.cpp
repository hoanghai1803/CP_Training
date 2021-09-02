// Author: BruteForce - Problem A
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

long long Nodes[4 * MAX_N];

long long Update(int id, int L, int R, int pos, int val) {
    if (pos < L || R < pos)
        return Nodes[id];
    if (L == R) 
        return (Nodes[id] = val);

    int M = (L + R) >> 1;
    return (Nodes[id] = Update(id * 2, L, M, pos, val) + Update(id * 2 + 1, M + 1, R, pos, val));
}

long long Get(int id, int L, int R, int u, int v) {
    if (v < L || u > R) 
        return 0;
    if (u <= L && R <= v) 
        return Nodes[id];

    int M = (L + R) >> 1;
    return Get(id * 2, L, M, u, v) + Get(id * 2 + 1, M + 1, R, u, v);
}

int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, q, a;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        Update(1, 1, n, i, a);
    }
    
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
            Update(1, 1, n, a, b);
        else 
            cout << Get(1, 1, n, a, b) << "\n";
    }
}