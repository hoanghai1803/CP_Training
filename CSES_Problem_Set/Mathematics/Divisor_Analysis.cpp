// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MOD (int)(1e9 + 7)

typedef long long int64;

int64 Pow(int64 a, int64 n) {
    int64 res = 1;
    while (n) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    int64 p, k;
    int64 cnt = 1, cnt2 = 1, sum = 1, product = 1;
    for (cin >> n; n--;) {
        cin >> p >> k;
        cnt = cnt * (k + 1) % MOD;
        sum = sum * (Pow(p, k + 1) - 1) % MOD * Pow(p - 1, MOD - 2) % MOD;
        product = Pow(product, k + 1) * Pow(Pow(p, k * (k + 1) / 2), cnt2) % MOD;
        cnt2 = cnt2 * (k + 1) % (MOD - 1);

    }
    cout << cnt << " " << sum << " " << product << "\n";
}