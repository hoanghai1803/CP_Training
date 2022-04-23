// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MOD (int64)(1e9 + 7)

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int64 n;
    cin >> n;

    int64 res = 0;
    for (int64 i = 1, j; i <= n; i = j) {
        int64 q = n / i; j = n / q + 1;
        int64 x = j - i, y = i + j - 1;
        if (x & 1) y /= 2;
        else x /= 2;
        x %= MOD, y %= MOD;
        res = (res + q % MOD * x % MOD * y % MOD) % MOD;
        i = j;
    }
    cout << res << "\n";
}