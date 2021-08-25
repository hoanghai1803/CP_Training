// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    vector<bool> chk1(n + 1, false);
    for (int i = 1, minVal = a[n]; i <= n; i++) {
        chk1[i] = a[i - 1] < minVal;
        minVal = min(minVal, a[i] + a[n]);
    }

    vector<bool> chk2(n + 1, false);
    for (int i = n, minVal = a[n]; i; i--) {
        chk2[i] = a[i - 1] < minVal;
        minVal = min(minVal, a[i - 1]);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res += chk1[i] && chk2[i];
    cout << res << "\n";
}