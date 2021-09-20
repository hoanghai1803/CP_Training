// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1003

int m, n;
string a[MAX_N];
int h[MAX_N], L[MAX_N];
long long dp[MAX_N], res;

void Calc(int row) {
    for (int i = 1; i <= n; i++)
        h[i] = (a[row][i] - '0') * (h[i] + 1);
    
    stack<int> St;
    St.push(0);
    for (int i = 1; i <= n; i++) {
        while (St.size() > 1 && h[St.top()] >= h[i]) St.pop();
        L[i] = St.top();
        St.push(i);
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i] = h[i] * (1LL * i - L[i]) + dp[L[i]];
        res += dp[i];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
        Calc(i);
    }

    cout << res << "\n";
}