// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

#define X first
#define Y second
#define MAX_N 1003

int m, n, k;
int64 S[MAX_N][MAX_N];

int64 getSum(ii tl, ii br) {
    return S[br.X][br.Y] - S[br.X][tl.Y - 1] - S[tl.X - 1][br.Y] + S[tl.X - 1][tl.Y - 1];
}

int64 bsRow(ii tl, ii br, int64 lim) {
    int L = tl.X, R = br.X, p = 0;
    while (true) {
        int M = (L + R) >> 1;
        if (M == L || M == R) {
            p = (2 * getSum(tl, {R, br.Y}) <= lim) ? R : L;
            break;
        }
        if (2 * getSum(tl, {M, br.Y}) <= lim) 
            L = M;
        else 
            R = M;
    }
    if (p == br.X)
        return lim;
    return min(abs(lim - 2 * getSum(tl, {p, br.Y})), abs(2 * getSum(tl, {p + 1, br.Y}) - lim));
}

int64 bsCol(ii tl, ii br, int64 lim) {
    int L = tl.Y, R = br.Y, p = 0;
    while (true) {
        int M = (L + R) >> 1;
        if (M == L || M == R) {
            p = (2 * getSum(tl, {br.X, R}) <= lim) ? R : L;
            break;
        }

        if (2 * getSum(tl, {br.X, M}) <= lim) 
            L = M;
        else 
            R = M;
    }
    if (p == br.Y)
        return lim;
    return min(abs(lim - 2 * getSum(tl, {br.X, p})), abs(2 * getSum(tl, {br.X, p + 1}) - lim));
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            int val;
            cin >> val;
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + val;
        }

    while (k--) {
        ii tl, br;
        cin >> tl.X >> tl.Y >> br.X >> br.Y;
        int64 lim = getSum(tl, br);
        cout << min(bsRow(tl, br, lim), bsCol(tl, br, lim)) << "\n";
    }
}