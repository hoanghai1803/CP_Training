// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t, n;
    for (cin >> t; t--;) {
        cin >> n;
        vector<int> a(n), L(n), R(n);
        for (int& x: a) cin >> x;
        
        stack<int> St;
        for (int i = 0; i < n; i++) {
            while (St.size() && a[St.top()] >= a[i]) St.pop();
            L[i] = St.size() ? St.top() + 1 : 0;
            St.push(i);
        }

        St = stack<int> {};
        for (int i = n - 1; i >= 0; i--) {
            while (St.size() && a[St.top()] >= a[i]) St.pop();
            R[i] = (St.size()) ? St.top() + 1 : n + 1;
            St.push(i);
        }

        int res = 0, Lmax = n, Rmax = 0;
        for (int i = 0; i < n; i++) {
            int temp = (R[i] - L[i] - 1) * a[i];
            if (temp > res || (temp == res && L[i] < Lmax)) 
                res = temp, Lmax = L[i], Rmax = R[i];
        }

        cout << res << " " << Lmax + 1 << " " << Rmax - 1 << "\n";
    }
}