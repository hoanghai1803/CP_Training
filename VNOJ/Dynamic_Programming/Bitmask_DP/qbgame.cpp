// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define oo LLONG_MAX
#define MAX_R 11
#define MAX_C 10004
#define MAX_STT (1 << MAX_R)

int n;
int a[MAX_R][MAX_C];
vector<int> valid_stt;
int64 dp[MAX_C][MAX_STT];

bool get_bit(int msk, int i) {
    return (msk >> i) & 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    int max_val = -1e9;
    for (int r = 0; r < 8; r++)
        for (int c = 0; c < n; c++) {
            cin >> a[r][c];
            max_val = max(max_val, a[r][c]);
        }
    if (max_val < 0) {
        cout << max_val << "\n";
        return 0;
    }

    int last_stt = (1 << 8) - 1;
    for (int stt = 0; stt <= last_stt; stt++) {
        bool chk = true;
        for (int i = 0; i < 7; i++)
            if (get_bit(stt, i) && get_bit(stt, i + 1)) 
                chk = false;
        if (chk) valid_stt.push_back(stt);
    }
    
    for (int stt: valid_stt) {
        for (int r = 0; r < 8; r++)
            if (get_bit(stt, r)) dp[0][stt] += a[r][0];
    }
    for (int c = 1; c < n; c++) 
        for (int stt: valid_stt) {
            dp[c][stt] = -oo;
            for (int pre_stt: valid_stt) {
                if (stt & pre_stt) continue;
                int64 score = dp[c - 1][pre_stt];
                for (int r = 0; r < 8; r++)
                    if (get_bit(stt, r)) score += a[r][c];
                dp[c][stt] = max(dp[c][stt], score);
            }
        }

    int64 ans = -oo;
    for (int stt: valid_stt)
        ans = max(ans, dp[n - 1][stt]);
    cout << ans << "\n";
}