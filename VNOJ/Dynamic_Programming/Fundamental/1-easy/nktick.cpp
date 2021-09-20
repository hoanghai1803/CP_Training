// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> t(n), r(n - 1), dp(n);
    for (int& x: t) cin >> x;
    for (int& x: r) cin >> x;

    dp[0] = t[0], dp[1] = min(t[0] + t[1], r[0]);
    for (int i = 2; i < n; i++)
        dp[i] = min(dp[i - 2] + r[i - 1], dp[i - 1] + t[i]);
    cout << dp[n - 1] << "\n";
}
