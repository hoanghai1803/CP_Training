// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define oo INT_MAX
#define MAX_N 18
#define MAX_MSK (1 << MAX_N)

int n, k;
int c[MAX_N][MAX_N];
int64 dp[MAX_MSK][MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];

    // Bitmask DP
    for (int msk = 1; msk < (1 << n); msk++) {
        if (__builtin_popcount(msk) == 1) continue;
        for (int i = 0; i < n; i++) 
            if((msk >> i) & 1) {
                dp[msk][i] = +oo;
                for (int j = 0; j < n; j++) {
                    if (j == i) continue;
                    if (((msk >> j) & 1)) 
                        dp[msk][i] = min(dp[msk][i], dp[msk & ~(1 << i)][j] + c[j][i]);
                }
            }
    }
    
    cout << *min_element(dp[(1 << n) - 1], dp[(1 << n) - 1] + n) << "\n";
}