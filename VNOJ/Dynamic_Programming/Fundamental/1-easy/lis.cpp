// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

template <class X>
void maximize(X& a, X b) {
    if (a < b) a = b;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int64> a(n);
    for (auto& x : a) cin >> x;

    vector<int64> b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());

    for (int i = 0; i < n; i++)
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;

    vector<int> bit(n + 1), dp(n + 1);
    auto update = [&](int p, int v) {
        for (; p < n; p += p & -p) maximize(bit[p], v);
    };

    auto get = [&](int p) {
        int ans = 0;
        for (; p; p -= p & -p) maximize(ans, bit[p]);
        return ans;
    };

    for (int i = 0; i < n; i++) {
        maximize(dp[a[i]], get(a[i] - 1) + 1);
        update(a[i], dp[a[i]]);
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}