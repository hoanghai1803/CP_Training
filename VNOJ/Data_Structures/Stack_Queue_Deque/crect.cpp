// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for (int i=(a); i<=(b); i++)

#define MAX_N 444

int m, n;
string str[MAX_N];
int h[MAX_N], L[MAX_N];
long long dp[MAX_N];
long long res;

void Calc(int row, int X, int Y, int Z, int sign) {
    FOR(i, 1, n)
        h[i] = (h[i] + 1) * (str[row][i] == X || str[row][i] == Y || str[row][i] == Z);

    stack<int> St;
    St.push(0);
    FOR(i, 1, n) {
        while (St.size() > 1 && h[St.top()] >= h[i]) St.pop();
        L[i] = St.top();
        St.push(i);
    }

    FOR(i, 1, n) {
        dp[i] = h[i] * (1LL * i - L[i]) + dp[L[i]];
        res += dp[i] * sign;
    }
}

void Reset() {
    FOR(i, 1, n) h[i] = 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> str[i];
        str[i] = " " + str[i];
    }

    FOR(x, 'A', 'C')
        FOR(y, x+1, 'D')
            FOR(z, y+1, 'E') {
                FOR(i, 1, m) Calc(i, x, y, z, 1); Reset();
                FOR(i, 1, m) Calc(i, x, y, 0, -1); Reset();
                FOR(i, 1, m) Calc(i, y, z, 0, -1); Reset();
                FOR(i, 1, m) Calc(i, z, x, 0, -1); Reset();
                FOR(i, 1, m) Calc(i, x, 0, 0, 1); Reset();
                FOR(i, 1, m) Calc(i, y, 0, 0, 1); Reset();
                FOR(i, 1, m) Calc(i, z, 0, 0, 1); Reset();
            }

    cout << res << "\n";
}