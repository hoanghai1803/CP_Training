// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define oo (int64)(1e15)
#define MAX_N 1003

int q, m, n, c;
int64 dp[MAX_N][MAX_N][2];

int main() {
    cin.tie(0)->sync_with_stdio(false);


    for (int i = 1; i < MAX_N; i++) dp[i][0][1] = +oo;
    for (int j = 1; j < MAX_N; j++) dp[0][j][0] = +oo;

    for (cin >> q; q--;) {
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                cin >> c;
                dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + c);
                dp[i][j][1] = min(dp[i][j - 1][1], dp[i][j - 1][0] + c);
            }
        cout << min(dp[m][n][0], dp[m][n][1]) << "\n";
    }
}