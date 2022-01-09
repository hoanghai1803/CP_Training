#include <bits/stdc++.h>

using namespace std;

const int MAX_N = (1 << 17) + 17;

int n, m, a;
int max_depth;
int Nodes[MAX_N * 4];

void Update(int depth, int id, int L, int R, int i, int val) {
    if (i < L || i > R) 
        return;

    if (L == R) {
        Nodes[id] = val;
        return;
    }

    int M = (L + R) >> 1;
    Update(depth + 1, id * 2 + 1, L, M, i, val);
    Update(depth + 1, id * 2 + 2, M + 1, R, i, val);

    if ((n - depth) & 1)
        Nodes[id] = Nodes[id * 2 + 1] | Nodes[id * 2 + 2];
    else    
        Nodes[id] = Nodes[id * 2 + 1] ^ Nodes[id * 2 + 2];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    int arr_len = 1 << n;
    for (int i = 0; i < arr_len; i++) {
        cin >> a;
        Update(0, 0, 0, arr_len - 1, i, a);
    }

    while (m--) {
        int p, b;
        cin >> p >> b;
        Update(0, 0, 0, arr_len - 1, p - 1, b);
        cout << Nodes[0] << "\n";
    }
}