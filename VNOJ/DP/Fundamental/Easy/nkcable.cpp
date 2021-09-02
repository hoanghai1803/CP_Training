// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n - 1), dp(n);
    for (int& x: a) cin >> x;

    dp[1] = a[0], dp[2] = a[0] + a[1];
    for (int i = 3; i < n; i++) 
        dp[i] = min(dp[i - 2], dp[i - 1]) + a[i - 1];
    cout << dp[n - 1] << "\n";
}

