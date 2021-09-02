// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define abs(x) ((x)>0?(x):-(x))

const int M = 16;
const int DIGITS = 20;
const int BAD = 20;
const int SIGNIFICANT_DIGITS = 2;
const int TIGHT = 2;

ll a, b;
int x, k;
int digits[M + 3];
ll memo[M + 3][DIGITS][BAD][SIGNIFICANT_DIGITS][TIGHT];

ll Dp(int idx, int last_digit, int num_bad, int sig_digits, int tight) {
    if (idx > M) return 1;
    ll& ret = memo[idx][last_digit][num_bad][sig_digits][tight];
    if (ret != -1) return ret;
    ret = 0;

    int max_d = tight ? digits[idx] : 9;
    for (int d = 0; d <= max_d; d++) {
        int bad_pos = sig_digits && (abs(d - last_digit) <= x);
        if (num_bad == k && bad_pos) continue;

        int new_num_bad = num_bad + bad_pos;
        int new_sig_digits = sig_digits || d;
        int new_tight = tight && (d == digits[idx]); 

        ret += Dp(idx + 1, d, new_num_bad, new_sig_digits, new_tight);
    }

    return ret;
}

ll Calc(ll n) {
    for (int i = M; i >= 1; i--)
        digits[i] = n % 10, n /= 10;
    memset(memo, -1, sizeof(memo));
    return Dp(1, 0, 0, 0, 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> a >> b >> x >> k;
    cout << Calc(b) - Calc(a - 1) << "\n";
}
