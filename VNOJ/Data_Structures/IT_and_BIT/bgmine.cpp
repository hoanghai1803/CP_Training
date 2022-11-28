// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MAX_N 100005
#define oo LLONG_MAX

struct gold_mine {
    int x, g, r;

    bool operator < (const gold_mine& other) const {
        return x < other.x;
    }
};

int n;
gold_mine mines[MAX_N];
int64 pref_G[MAX_N], pref_R[MAX_N];
int64 Nodes[MAX_N * 4];
int64 res = 0;

void update(int id, int L, int R, int p, int64 val) {
    if (p < L || p > R) return;
    if (L == R) {
        Nodes[id] = val;
        return;
    }

    int M = (L + R) >> 1;
    update(id << 1, L, M, p, val);
    update((id << 1) + 1, M + 1, R, p, val);
    Nodes[id] = min(Nodes[id << 1], Nodes[(id << 1) + 1]);
}

int findPos(int id, int L, int R, int64 key) {
    if (L == R) 
        return L;
    int M = (L + R) >> 1;
    if (Nodes[id << 1] <= key)
        return findPos(id << 1, L, M, key);
    return findPos((id << 1) + 1, M + 1, R, key);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (int i = 1; i < 4 * MAX_N; i++)
        Nodes[i] = +oo;
    
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> mines[i].x >> mines[i].g >> mines[i].r;
    sort (mines + 1, mines + 1 + n);

    for (int i = 1; i <= n; i++) {
        pref_G[i] = pref_G[i - 1] + mines[i].g;
        pref_R[i] = pref_R[i - 1] + mines[i].r;
        int64 key = pref_R[i] - mines[i].x;
        update(1, 1, n, i, pref_R[i - 1] - mines[i].x);
        if (Nodes[1] <= key) {
            int pos = findPos(1, 1, n, key);
            res = max(res, pref_G[i] - pref_G[pos - 1]);
        }
    }
    cout << res << "\n";
}