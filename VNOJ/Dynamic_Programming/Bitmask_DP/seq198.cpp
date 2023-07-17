// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MASK_FULL ((1 << 10) - 1)
#define MASK_198 ((1 << 1) + (1 << 8) + (1 << 9))

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    sort(a.begin(), a.end());

    vector<int> dp(MASK_FULL + 10, -1), pre_dp(MASK_FULL + 10, -1);
    dp[0] = 0;
    dp[1 << 0] = 1;

    for (int i = 1; i < n; i++) {
        int diff = a[i] - a[i - 1];
        pre_dp.swap(dp);
        dp.assign(MASK_FULL + 10, -1);
        for (int msk = 0; msk <= MASK_FULL; msk++)
            if (pre_dp[msk] != -1) {
                int new_msk = diff > 10 ? 0 : (msk << diff) & MASK_FULL; // get last 10 bit
                dp[new_msk] = max(dp[new_msk], pre_dp[msk]); // do not choose a[i]
                if (new_msk & MASK_198) continue;
                dp[new_msk | 1] = max(dp[new_msk | 1], pre_dp[msk] + 1); // choose a[i]
            }
    }

    int ans = 0;
    for (int msk = 0; msk <= MASK_FULL; msk++)
        ans = max(ans, dp[msk]);
    cout << n - ans << "\n";
}