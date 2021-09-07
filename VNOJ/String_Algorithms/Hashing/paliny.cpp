// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5e4 + 4;
const int MOD = 1e9 + 9;
const int BASE = 31;

int n;
string str;
int res;
long long lHash[MAX_N], rHash[MAX_N], Pow[MAX_N];

long long getLeftHash(int l, int r) {
    return (lHash[r] - lHash[l - 1] * Pow[r - l + 1] + 1LL * MOD * MOD) % MOD;
}

long long getRightHash(int l, int r) {
    return (rHash[l] - rHash[r + 1] * Pow[r - l + 1] + 1LL * MOD * MOD) % MOD;
}

bool Check(int len, int k) {
    for (int i = 1; i <= n; i++) {
        int l = i - k - len + 1;
        if (l < 1) continue;
        int r = i + len;
        if (r > n) break;

        if (getLeftHash(l, i - k) == getRightHash(i + 1, r))
            return true;
    }
    return false;
}

int BinarySearch(int L, int R, int k) {
    while (true) {
        int M = (L + R) >> 1;
        if (M == L || M == R) {
            if (Check(R, k)) return R;
            if (Check(L, k)) return L;
            return 0;
        }

        if (Check(M, k)) L = M;
        else R = M;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    cin >> str;
    str = " " + str;

    Pow[0] = 1;
    for (int i = 1; i <= n; i++) {
        lHash[i] = (lHash[i - 1] * BASE + str[i] - 'a') % MOD;
        Pow[i] = Pow[i - 1] * BASE % MOD;
    }
    for (int i = n; i >= 1; i--) 
        rHash[i] = (rHash[i + 1] * BASE + str[i] - 'a') % MOD;

    res = max(res, BinarySearch(1, n - (n & 1), 0) * 2);
    res = max(res, BinarySearch(1, n - !(n & 1), 1) * 2 + 1);

    cout << res << "\n";
}
