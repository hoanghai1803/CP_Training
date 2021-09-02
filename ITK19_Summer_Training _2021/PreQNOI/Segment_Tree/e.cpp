// Author: BruteForce - Problem E
#include <bits/stdc++.h>

using namespace std;

#define max3(a,b,c) (max(a,max(b,c)))

#define MAX_N 100005

struct Node {
    long long maxSum, sum, left, right;
} Nodes[4 * MAX_N];

void Update(int id, int L, int R, int pos, int val) {
    if (pos < L || R < pos)
        return;
    if (L == R) {
        Nodes[id] = {val, val, val, val};
        return;
    }

    int M = (L + R) >> 1;
    Update(id * 2, L, M, pos, val);
    Update(id * 2 + 1, M + 1, R, pos, val);

    Nodes[id].sum = Nodes[id * 2].sum + Nodes[id * 2 + 1].sum;
    Nodes[id].left = max(Nodes[id * 2].left, Nodes[id * 2].sum + Nodes[id * 2 + 1].left);
    Nodes[id].right = max(Nodes[id * 2].right + Nodes[id * 2 + 1].sum, Nodes[id * 2 + 1].right);
    Nodes[id].maxSum = max3(Nodes[id * 2].maxSum, Nodes[id * 2 + 1].maxSum, Nodes[id * 2].right + Nodes[id * 2 + 1].left);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, p, q, val;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        Update(1, 1, n, i, val);
    }

    while (q--) {
        cin >> p >> val;
        Update(1, 1, n, p, val);
        cout << Nodes[1].maxSum << "\n";
    }
}