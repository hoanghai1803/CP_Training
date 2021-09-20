// Author: __BruteForce__
#include <bits/stdc++.h>                                       
                                                              
using namespace std;                                           

#define MAX_N 3003
#define MAX_K 10

int n, k[MAX_K + 3], x;
int dp[2][MAX_N][MAX_K + 3];
string s;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // Input
    cin >> n >> s;
    x = s.length() - 1;
    for (int i = 1; i <= n; i++) cin >> k[i];

    // DP
    for (int i = x; i >= 0; i--)
        for (int j = i; j <= x; j++) {
            dp[i][j][0] = 0;
            if (s[i] == s[j]) dp[i][j][0] = dp[i + 1][j + 1][0] + 1;
        }
    for (int i = x; i >= 0; i--)
        for (int j = x; j >= i; j--)
            for (int t = 1; t <= MAX_K; t++)
                dp[i][j][t] = (s[i] == s[j] ? dp[i + 1][j + 1][t] + 1 : dp[i + 1][j + 1][t - 1] + 1);

    // Calculating result
    for (int t = 1; t <= n; t++) {
        int res = 0;
        for (int i = 0; i <= x - 2; i++)
            for (int j = i; j <= x - 2; j++)
                if (dp[i][j + 1][k[t]] >= j - i + 1) res = max(res, j - i + 1);
        cout << res << "\n";
    }
}
