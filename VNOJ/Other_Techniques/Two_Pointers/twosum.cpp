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

    int res = 0;
    for (int L = 1; L < n; L++) {
        for (int M = L, R = L + 1; R <= n; R++) {
            while (M < R - 1 && (a[M] - a[L - 1]) * 2 < a[R] - a[L - 1])
                M++;
            if (M > L && a[M - 1] - a[L - 1] == a[R] - a[M - 1]) 
                res = max(res, R - L + 1);
            if (a[M] - a[L - 1] == a[R] - a[M])
                res = max(res, R - L + 1);
        }
    }

    cout << res << "\n";
}