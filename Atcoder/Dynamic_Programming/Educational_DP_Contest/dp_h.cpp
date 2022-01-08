// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1111
#define MOD (int)(1e9 + 7)

int h, w;
char ch;
int dp[MAX_N][MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> h >> w;
    for (int i = 1; i <= h; i++) 
        for (int j = 1; j <= w; j++) {
            cin >> ch;
            if (ch == '#') continue;
            if (i == 1 && j == 1) 
                dp[i][j] = 1;
            else 
                dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % MOD, dp[i][j] %= MOD;
        }
    cout << dp[h][w] << "\n";
}