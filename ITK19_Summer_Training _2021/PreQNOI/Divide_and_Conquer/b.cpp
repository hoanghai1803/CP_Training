#include <bits/stdc++.h>

using namespace std;

#define sqr(x) (1LL*(x)*(x))

#define oo LLONG_MAX
#define MAX_N 100005

struct Point {
    int x, y;

    bool operator < (Point rhs) {
        return y < rhs.y || (y == rhs.y && x < rhs.x);
    }
} p[MAX_N];

long long dist(Point a, Point b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

long long Calc(int L, int R) {
    if (L >= R) 
        return +oo;

    int M = (L + R) >> 1;
    long long d = min(Calc(L, M), Calc(M + 1, R));

    vector<Point> nr;
    for (int i = M; i >= L && p[M].x - p[i].x < d; i--) 
        nr.push_back(p[i]);
    for (int i = M + 1; i <= R && p[i].x - p[M].x < d; i++)
        nr.push_back(p[i]);
    sort(nr.begin(), nr.end());

    long long ret = d;
    for (int i = 0; i < nr.size(); i++)
        for (int j = i + 1; j < nr.size() && sqr(nr[j].y - nr[i].y) < ret; j++)
            ret = min(ret, dist(nr[i], nr[j]));
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, a, pref;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        pref += a;
        p[i] = {i, pref};
    }

    cout << Calc(1, n) << "\n";
}