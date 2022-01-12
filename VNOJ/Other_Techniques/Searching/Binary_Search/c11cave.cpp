// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, h;
    vector<int> a, b;

    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i & 1) a.push_back(x);
        else b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int res = n + 1, cnt = 0;
    for (int i = 1; i <= h; i++) {
        int stones_1 = a.end() - lower_bound(a.begin(), a.end(), i);
        int stones_2 = b.end() - lower_bound(b.begin(), b.end(), h - i + 1);
        if (stones_1 + stones_2 == res) cnt++;
        if (stones_1 + stones_2 < res) res = stones_1 + stones_2, cnt = 1;
    }

    cout << res << " " << cnt << "\n";
}