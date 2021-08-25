// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int c, n;
    cin >> c >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;

    int res = 0;
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1) sum += a[j];
        if (sum <= c)
            res = max(res, sum);
    }

    cout << res << "\n";
}   