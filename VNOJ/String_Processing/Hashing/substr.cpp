// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 6;
const int MOD = 1e9 + 9;
const int BASE = 29;

string a, b;
long long hashA[MAX_N], Pow[MAX_N];

long long getHash(int l, int r) {
    return (hashA[r] - hashA[l - 1] * Pow[r - l + 1] + 1LL * MOD * MOD) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> a >> b;
    a = " " + a;
    int lenA = a.length(), lenB = b.length();

    long long hashB = b[0] - 'a';
    for (int i = 1; i < lenB; i++)
        hashB = (hashB * BASE + b[i] - 'a' ) % MOD;

    Pow[0] = 1;
    for (int i = 1; i < lenA; i++) {
        hashA[i] = (hashA[i - 1] * BASE + a[i] - 'a') % MOD;
        Pow[i] = Pow[i - 1] * BASE % MOD;
        if (i < lenB) continue;
        if (getHash(i - lenB + 1, i) == hashB)
            cout << i - lenB + 1 << " ";
    }
}
