#include <bits/stdc++.h>

using namespace std;

#define MAX_N 505

int n, m, q;
char s[MAX_N][MAX_N];
int nearest[MAX_N][MAX_N];
int dp[MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++)
            for (int k = j; k <= m; k++)
                if (s[i][k] == '#') {
                    nearest[i][j] = k;
                    break;
                }
    }

    for (cin >> q; q--;) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        memset(dp, 0, sizeof(dp));
        
    }
}