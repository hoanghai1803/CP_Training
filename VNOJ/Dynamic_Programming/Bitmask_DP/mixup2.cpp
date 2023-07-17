// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MAX_N 18
#define MAX_MSK (1 << MAX_N)

int n, k;
int s[MAX_N];
int64 dp[MAX_MSK][MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    // Bitmask DP
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = 1;
    for (int msk = 1; msk < (1 << n); msk++) {
        if (__builtin_popcount(msk) == 1) continue;
        for (int i = 0; i < n; i++) 
            if((msk >> i) & 1) {
                for (int j = 0; j < n; j++) {
                    if (j == i) continue;
                    if (((msk >> j) & 1) && abs(s[i] - s[j]) > k) 
                        dp[msk][i] += dp[msk & ~(1 << i)][j];
                }
            }
    }
    
    int64 ans = 0;
    for (int i = 0; i < n; i++) ans += dp[(1 << n) - 1][i];
    cout << ans << "\n";
}