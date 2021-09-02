// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 16;
const int DIGITS = 10;
const int TIGHT = 2;

int digits[M + 3];
ll memo[M + 3][DIGITS + 3][TIGHT];

ll Dp(int idx, int last_digit, int tight) {
    if (idx > M) return 1;
    ll& ret = memo[idx][last_digit][tight];
    if (ret != -1) return ret;
    ret = 0;

    int max_d = tight ? digits[idx] : 9;
    for (int d = 0; d <= max_d; d++) {
        if (last_digit == 1 && d == 3) continue;
        int new_tight = tight && (d == digits[idx]);
        ret += Dp(idx + 1, d, new_tight);
    }
    
    return ret;
}

ll Calc(ll n) {
    for (int i = M; i >= 1; i--)
        digits[i] = n % 10, n /= 10;
    memset(memo, -1, sizeof(memo));
    return Dp(1, 0, 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("lucky13.inp", "r", stdin);
        freopen("lucky13.out", "w", stdout);
    #endif
    
    ll a, b;
    while (cin >> a >> b) {
        cout << Calc(b) - Calc(a - 1) << "\n";
    }
}
