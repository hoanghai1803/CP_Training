// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_XY 4444
#define N 1003

#define rect(x, y, k) x + y - k, x + y + k, x - y - k + N, x - y + k + N

template <class X>
void maximize(X &a, X b) {
    if (a < b) a = b;
}

struct dir {
    int id, tl, tr;

    dir(int _id, int _tl, int _tr) : id(_id), tl(_tl), tr(_tr) {}

    dir left_node() const { return dir(id << 1, tl, tl + tr >> 1); }
    dir right_node() const {
        return dir((id << 1) + 1, (tl + tr >> 1) + 1, tr);
    }
    bool irrelevant(int ql, int qr) const {
        return tl > qr || ql > tr || ql > qr;
    }
};

int ST[MAX_XY][MAX_XY];

void update(const dir &dx, const dir &dy, int x, int y, int val, bool only_y) {
    if (dx.irrelevant(x, x) || dy.irrelevant(y, y)) return;
    maximize(ST[dx.id][dy.id], val);
    if (!only_y && dx.tl != dx.tr) {
        update(dx.left_node(), dy, x, y, val, false);
        update(dx.right_node(), dy, x, y, val, false);
    }
    if (dy.tl != dy.tr) {
        update(dx, dy.left_node(), x, y, val, true);
        update(dx, dy.right_node(), x, y, val, true);
    }
}

int get_max(const dir &dx, const dir &dy, int lx, int rx, int ly, int ry) {
    if (dx.irrelevant(lx, rx) || dy.irrelevant(ly, ry)) return 0;
    if (lx <= dx.tl && dx.tr <= rx) {
        if (ly <= dy.tl && dy.tr <= ry) return ST[dx.id][dy.id];
        int m1 = get_max(dx, dy.left_node(), lx, rx, ly, ry);
        int m2 = get_max(dx, dy.right_node(), lx, rx, ly, ry);
        return max(m1, m2);
    } else {
        int m1 = get_max(dx.left_node(), dy, lx, rx, ly, ry);
        int m2 = get_max(dx.right_node(), dy, lx, rx, ly, ry);
        return max(m1, m2);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n), c(n);
    dir dx(1, 0, N + N), dy(1, 0, N + N);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> c[i];
    for (int i = n - 1; i >= 0; i--) {
        int max_val = get_max(dx, dy, rect(x[i], y[i], k)) + c[i];
        update(dx, dy, x[i] + y[i], x[i] - y[i] + N, max_val, false);
    }
    cout << get_max(dx, dy, rect(0, 0, k)) << "\n";
}