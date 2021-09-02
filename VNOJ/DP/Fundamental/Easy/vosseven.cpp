// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    string s;
    cin >> s;
    vector<int> dp(s.length() + 1);
    int len = 0, n = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == '7') 
            dp[++len]++, n = max(n, len);
        else 
            len = 0;
    }

    for (int i = n - 1; i; i--)
        dp[i] += dp[i + 1];
    for (int i = 1; i <= n; i++)
        cout << i << " " << dp[i] << "\n";
}
