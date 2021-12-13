// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pref[i] = pref[i - 1] ^ x;
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (pref[a - 1] ^ pref[b]) << "\n";
    }
}