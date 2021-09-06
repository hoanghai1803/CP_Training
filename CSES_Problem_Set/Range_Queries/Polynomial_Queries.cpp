// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 200005
 
int arr[MAX_N];
 
struct Node {
    long long sum, lazy;
    int inc;
} Nodes[4 * MAX_N];
 
long long Build(int id, int L, int R) {
    if (L == R) 
        return (Nodes[id].sum = arr[L]);
    int M = (L + R) >> 1;
    return (Nodes[id].sum = Build(id * 2, L, M) + Build(id * 2 + 1, M + 1, R));
}
 
void Propagation(int id, int L, int R) {
    int M = (L + R) >> 1;
 
    long long lz = Nodes[id].lazy;
    Nodes[id * 2].sum += lz * (M - L + 1), Nodes[id * 2].lazy += lz;
    Nodes[id * 2 + 1].sum += lz * (R - M), Nodes[id * 2 + 1].lazy += lz;
    Nodes[id].lazy = 0;
 
    int inc = Nodes[id].inc;
    Nodes[id * 2].sum += 1LL * inc * (M - L + 1) * (L + M) / 2;
    Nodes[id * 2].inc += inc;
    Nodes[id * 2 + 1].sum += 1LL * inc * (R - M) * (M + 1 + R) / 2;
    Nodes[id * 2 + 1].inc += inc;
    Nodes[id].inc = 0;
}
 
long long Update(int id, int L, int R, int u, int v, int val) {
    if (v < L || R < u)
        return Nodes[id].sum;
    if (u <= L && R <= v)  {
        Nodes[id].sum += 1LL * (R - L + 1) * val + 1LL * (R - L + 1) * (L + R) / 2;
        Nodes[id].lazy += val, Nodes[id].inc++;
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
 
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) 
        cin >> arr[i];
    Build(1, 1, n);
    
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) 
            Update(1, 1, n, l, r, 1 - l);
        else 
            cout << Get(1, 1, n, l, r) << "\n";
    }
}