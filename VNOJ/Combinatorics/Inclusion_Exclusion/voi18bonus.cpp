// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define oo LLONG_MAX
#define MAX_N 555

struct Point {
    int x, y;

    Point();
    Point(int _x, int _y): x(_x), y(_y) {} 

    bool operator == (Point rhs) {
        return (x == rhs.x && y == rhs.y);
    }
};

struct Rect {
    Point tl, br;

    Rect();
    Rect(Point _tl, Point _br): tl(_tl), br(_br) {}

    bool operator == (Rect rhs) {
        return (tl == rhs.tl && br == rhs.br);
    }
};

int n, k, r, p;
int64 S[MAX_N][MAX_N];

const Rect NULL_RECT = Rect(Point(-1, -1), Point(-1, -1));

Rect intersect(Rect r1, Rect r2) {
    int x1 = max(r1.tl.x, r2.tl.x);
    int x2 = min(r1.br.x, r2.br.x);
    int y1 = max(r1.tl.y, r2.tl.y);
    int y2 = min(r1.br.y, r2.br.y);

    if (x1 <= x2 && y1 <= y2) {
        return Rect(Point(x1, y1), Point(x2, y2));
    } else {
        return NULL_RECT;
    }
}

int64 calc(int x[], int y[]) {
    int64 ret = 0;
    for (int msk = 1; msk < (1 << p); msk++) {
        Rect board = Rect(Point(1, 1), Point(n, n));
        for (int j = 1; j <= p; j++) 
            if ((msk >> (j - 1)) & 1) {
                board = intersect(board, Rect(Point(x[j], y[j]), Point(x[j] + r - 1, y[j] + r - 1)));
            }
        if (board == NULL_RECT) continue;

        int64 intersectArea = S[board.br.x][board.br.y] - S[board.br.x][board.tl.y - 1]
                            - S[board.tl.x - 1][board.br.y] + S[board.tl.x - 1][board.tl.y - 1];
        if (__builtin_popcount(msk) & 1)
            ret += intersectArea;
        else 
            ret -= intersectArea;
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k >> r >> p;
    int val;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) {
            cin >> val;
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + val;
        }

    int64 res = -oo;
    while (k--) {
        int x[10], y[10];
        for (int i = 1; i <= p; i++)
            cin >> x[i] >> y[i];
        res = max(res, calc(x, y));
    }
    cout << res << "\n";
}