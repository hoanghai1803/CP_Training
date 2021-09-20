// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x: a) 
        cin >> x;
    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i < n - 2; i++) 
        for (int key = m - a[i], L = i + 1, R = n - 1; L < R; L++) {
            while (L < R - 1 && key < a[L] + a[R])
                R--;
            if (a[L] + a[R] <= key)
                res = max(res, a[i] + a[L] + a[R]);
        }

    cout << res << "\n";
}