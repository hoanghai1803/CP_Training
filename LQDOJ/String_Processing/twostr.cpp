// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3e3 + 3;
const int MOD[] = {(int)1e9 + 33, (int)1e9 + 181};
const int NUM_STR = 2;
const int NUM_MOD = 2;
const int BASE = 31;

int n;
string s1, s2;
long long hashCode[NUM_STR][NUM_MOD][MAX_N], Pow[NUM_MOD][MAX_N];

long long getHash(int id_str, int id_hash, int l, int r) {
    return (hashCode[id_str][id_hash][r] - hashCode[id_str][id_hash][l - 1] * Pow[id_hash][r - l + 1] + 1LL * MOD[id_hash] * MOD[id_hash]) % MOD[id_hash];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    cin >> s1 >> s2;
    s1 = " " + s1, s2 = " " + s2;

    Pow[0][0] = Pow[1][0] = 1;
    for (int k = 0; k < 2; k++) 
        for (int i = 1; i <= n; i++) { 
            hashCode[0][k][i] = (hashCode[0][k][i - 1] * BASE + s1[i] - 'a') % MOD[k];
            hashCode[1][k][i] = (hashCode[1][k][i - 1] * BASE + s2[i] - 'a') % MOD[k];
            Pow[k][i] = Pow[k][i - 1] * BASE % MOD[k];
        }

    int res = n;
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= n - i; j++) {
            int len = n - i - j;
            if (getHash(0, 0, i + 1, i + len) != getHash(1, 0, j + 1, j + len)) continue;
            if (getHash(0, 1, i + 1, i + len) != getHash(1, 1, j + 1, j + len)) continue;
            res = min(res, i + j);
        }
    cout << res << "\n";
}
