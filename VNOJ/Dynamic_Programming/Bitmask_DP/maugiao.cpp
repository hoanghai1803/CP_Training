// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int get_bit(int mask, int i) {
    return mask & (1 << i);
}

int off_bit(int mask, int i) {
    return mask & ~(1 << i);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    
    vector<int> dp(1 << n);
    vector<unsigned long long> cnt(1 << n);
    dp[0] = 0, cnt[0] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
        int j = __builtin_popcount(mask) - 1;
        for (int i = 0; i < n; i++) {
            if (!get_bit(mask, i)) continue;
            int dp_new = dp[off_bit(mask, i)] + a[i][j];
            if (dp[mask] == dp_new)
                cnt[mask] += cnt[off_bit(mask, i)];
            else if (dp[mask] < dp_new)
                dp[mask] = dp_new, cnt[mask] = cnt[off_bit(mask, i)];
        }
    }

    cout << dp[(1 << n) - 1] << " " << cnt[(1 << n) - 1] << "\n";
}