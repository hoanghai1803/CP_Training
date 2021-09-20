// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t, n, k;
    for (cin >> t; t--;) {
        cin >> n >> k;
        vector<int> a(n + 1), res(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        
        deque<int> Dq;
        Dq.push_back(1);
        res[1] = a[1];
        for (int i = 2; i <= n; i++) {
            if (Dq.front() == i - k) Dq.pop_front();
            while (Dq.size() && a[Dq.back()] >= a[i]) Dq.pop_back();
            Dq.push_back(i);
            res[i] = a[Dq.front()];
        }

        for (int i = k; i <= n; i++)
            cout << res[i] << " ";
        cout << "\n";
    }
}