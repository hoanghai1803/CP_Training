// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1003

int n, k;
int a[MAX_N][MAX_N], S[MAX_N][MAX_N];
int res = 0;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a[i][j];
            if (i >= k && j >= k) 
                res = max(res, S[i][j] - S[i - k][j] - S[i][j - k] + S[i - k][j - k]);
        }
    cout << res << "\n";
}