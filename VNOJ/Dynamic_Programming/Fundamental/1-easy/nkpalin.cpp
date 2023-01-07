// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 2222

string s;
int dp[MAX_N][MAX_N];
bool removed[MAX_N];

int calc(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r]) return dp[l][r];
    if (s[l] == s[r]) 
        return (dp[l][r] = calc(l + 1, r - 1) + 2);
    return (dp[l][r] = max(calc(l + 1, r), calc(l, r - 1)));
}

void trace(int l, int r) {
    if (l >= r) return;
    if (s[l] == s[r]) {
        trace(l + 1, r - 1);
    } else {
        if (dp[l][r] == dp[l][r - 1]) {
            removed[r] = true;
            trace(l, r - 1);
        } else {
            removed[l] = true;
            trace(l + 1, r);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> s;
    int n = s.size() - 1;
    for (int i = 0; i <= n; i++) dp[i][i] = 1;
    calc(0, n);
    trace(0, n);
    for (int i = 0; i <= n; i++)
        if (!removed[i]) cout << s[i];
}