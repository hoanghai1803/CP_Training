// Author: BruteForce - Problem F
#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define MAX_N 100005

int Nodes[4 * MAX_N];

int Update(int id, int L, int R, int pos, int val) {
    if (pos < L || R < pos)
        return Nodes[id];
    if (L == R) 
        return (Nodes[id] = val);

    int M = (L + R) >> 1;
    return (Nodes[id] = max(Update(id * 2, L, M, pos, val), Update(id * 2 + 1, M + 1, R, pos, val)));
}

int Binary_Search(int id, int L, int R, int key) {
    if (L == R) 
        return L;
    int M = (L + R) >> 1;
    if (Nodes[id * 2] >= key) 
        return Binary_Search(id * 2, L, M, key);
    return Binary_Search(id * 2 + 1, M + 1, R, key);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q, val;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        Update(1, 1, n, i, val);
    }

    while (q--) {
        int t, p, val;
        cin >> t;
        if (t == 1) {
            cin >> p >> val;
            Update(1, 1, n, p, val);
            continue;
        }
        cin >> val;
        cout << (Nodes[1] >= val ? Binary_Search(1, 1, n, val) : -1) << "\n";
    }
}