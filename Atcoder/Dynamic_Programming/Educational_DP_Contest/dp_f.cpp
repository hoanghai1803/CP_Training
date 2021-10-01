// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 3333

string s, t;
int dp[MAX_N][MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> s >> t;
    int lenS = s.size(), lenT = t.size();
    for (int i = 0; i < lenS; i++) 
        for (int j = 0; j < lenT; j++) {
            if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
            else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }

    string lcs = "";
    for (int i = lenS, j = lenT; i > 0 && j > 0;) {
        if (s[i - 1] == t[j - 1] && dp[i - 1][j - 1] + 1 == dp[i][j]) {
            lcs = s[i - 1] + lcs;
            i--, j--;
        } else if (dp[i - 1][j] == dp[i][j]) i--;
        else j--;
    }
    cout << lcs;
}