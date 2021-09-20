// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> h(n), L(n), R(n);
    for (int& x: h) cin >> x;

    stack<int> St;
    for (int i = 0; i < n; i++) {
        while (St.size() && h[St.top()] >= h[i]) St.pop();
        L[i] = St.size() ? St.top() : -1;
        St.push(i);
    }

    St = stack<int> {};
    for (int i = n - 1; i >= 0; i--) {
        while (St.size() && h[St.top()] >= h[i]) St.pop();
        R[i] = St.size() ? St.top() : n;
        St.push(i);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
        if (R[i] - L[i] - 1 >= h[i])
            res = max(res, h[i]);
    cout << res << "\n";
}