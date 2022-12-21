// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1111

int n, a[MAX_N], dp[MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            int key = a[i] - a[j];
            if (binary_search(a, a + j, key) || binary_search(a + j + 1, a + i, key)) 
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    
    cout << *max_element(dp, dp + n) << "\n";
}