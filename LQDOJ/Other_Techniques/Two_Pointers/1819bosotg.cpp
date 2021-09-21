// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    sort(a.begin(), a.end());

    long long res = 0;
    for (int i = 0; i < n - 2; i++) 
        for (int j = i + 2, k = i + 1; j < n; j++) {
            while (k < j && a[i] + a[k] <= a[j]) k++;
            res += j - k;
        }
    cout << res;
}