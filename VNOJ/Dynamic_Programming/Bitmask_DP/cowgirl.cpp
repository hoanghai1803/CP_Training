// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 33
#define MAX_STT (1 << 7)

int t, m, n;
int dp[MAX_N][MAX_STT];

bool get_bit(int msk, int i) {
    return (msk >> i) & 1;
}

bool valid(int stt1, int stt2) {
    int stt = stt1 & stt2;
    for (int i = 0; i < n - 1; i++)
        if (get_bit(stt, i) && get_bit(stt, i + 1)) return false;
    stt = stt1 | stt2;
    for (int i = 0; i < n - 1; i++)
        if (!get_bit(stt, i) && !get_bit(stt, i + 1)) return false;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> t; t--;) {
        cin >> m >> n;
        if (m < n) swap(m, n);

        // Bitmask DP
        int last_stt = (1 << n) - 1;
        for (int stt = 0; stt <= last_stt; stt++)
            dp[0][stt] = 1;
        for (int i = 1; i < m; i++) 
            for (int stt = 0; stt <= last_stt; stt++) {
                dp[i][stt] = 0;
                for (int pre_stt = 0; pre_stt <= last_stt; pre_stt++)
                    if (valid(pre_stt, stt)) dp[i][stt] += dp[i - 1][pre_stt];
            }

        int ans = 0;
        for (int stt = 0; stt <= last_stt; stt++)
            ans += dp[m - 1][stt];
        cout << ans << "\n";
    }
}