#include <bits/stdc++.h>

using namespace std;

const int oo = INT_MAX;

#define MAX_N 100005

int n, t;
int a[MAX_N];

int gcd(int a, int b) {
    return (!b) ? a : gcd(b, b % a);
}

struct Tree_Node {
    int minVal, numMin;
    int gcd;

    // Default Constructor
    Tree_Node() {}

    // Initialization Lists
    Tree_Node(int __minVal, int __numMin, int __gcd): 
        minVal(__minVal), numMin(__numMin), gcd(__gcd) {}
} Nodes[MAX_N * 4];

int cnt = 0;

Tree_Node Update(int id, int L, int R, int pos, int val) {
    if (pos < L || pos > R) 
        return Tree_Node(+oo, 0, 0);
    cout << id << " " << L << " " << R << "\n";
    if (++cnt == 10)
        exit(0);

    if (L == R) {
        a[pos] = val;
        Nodes[id] = {val, 1, val};
        return Nodes[id];
    }

    int M = (L + R) >> 1;
    Tree_Node node_left = Update(id * 2, L, M, pos, val);
    Tree_Node node_right = Update(id * 2 + 1, M + 1, R, pos, val);

    if (node_left.minVal <= node_right.minVal) {
        Nodes[id] = {node_left.minVal, node_left.numMin, gcd(node_left.gcd, node_right.gcd)};
        if (node_left.minVal == node_right.minVal)
            Nodes[id].numMin += node_right.numMin;
        return Nodes[id];
    }
    
    Nodes[id] = {node_right.minVal, node_right.numMin, gcd(node_left.gcd, node_right.gcd)};
    return Nodes[id];
}

Tree_Node Get(int id, int L, int R, int u, int v) {
    if (v < L || u > R)
        return Tree_Node(+oo, 0, 0);
    
    if (L >= u && R <= v) 
        return Nodes[id];

    int M = (L + R) >> 1;
    Tree_Node node_left = Get(id * 2, L, M, u, v);
    Tree_Node node_right = Get(id * 2 + 1, M + 1, R, u, v);

    if (node_left.minVal <= node_right.minVal) {
        Tree_Node node_temp = {node_left.minVal, node_left.numMin, gcd(node_left.gcd, node_right.gcd)};
        if (node_left.minVal == node_right.minVal)
            node_temp.numMin += node_right.numMin;
        return node_temp;
    }

    return Tree_Node(node_right.minVal, node_right.numMin, gcd(node_left.gcd, node_right.gcd));
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= 2; i++) {
        cin >> a[i];
        Update(1, 1, n, i, a[i]);
    }
    return 0;

    for (cin >> t; t--;) {
        int l, r;
        cin >> l >> r;
        Tree_Node ans = Get(1, 1, n, l, r);
        cout << (l - r + 1 - ans.numMin * (ans.minVal == ans.gcd)) << "\n";
    }
}