// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 3333

int n;
double p, dp[MAX_N][MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        dp[i][0] = dp[i - 1][0] * (1 - p);
        for (int j = 1; j <= i; j++) 
            dp[i][j] = dp[i - 1][j - 1] * p + dp[i - 1][j] * (1 - p);
    }

    double res = 0;
    for (int j = n / 2 + 1; j <= n; j++) res += dp[n][j];
    cout << fixed << setprecision(10) << res << "\n";
}