// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 6;
const int MOD[] = {(int)(1e9 + 9), (int)(1e9 + 409)};
const int BASE = 31;

int n;
string str;
long long hashCode[2][MAX_N], Pow[2][MAX_N];

long long getHash(int id, int l, int r) {
    long long diff = hashCode[id][r] - hashCode[id][l - 1] * Pow[id][r - l + 1];
    return (diff < 0 ? (diff + 1LL * MOD[id] * MOD[id]) % MOD[id] : diff);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> str;
    n = str.length(), str = " " + str;

    Pow[0][0] = Pow[1][0] = 1;
    for (int k = 0; k < 2; k++)
        for (int i = 1; i <= n; i++) {
            hashCode[k][i] = (hashCode[k][i - 1] * BASE + str[i] - 'a') % MOD[k];
            Pow[k][i] = Pow[k][i - 1] * BASE % MOD[k];
        }

    for (int len = 1; len <= n; len++) {
        bool chk = true;
        for (int i = len + 1; i <= n; i += len) {
            int minLen = min(len, n - i + 1);
            if (getHash(0, i, i + minLen - 1) != hashCode[0][minLen]) {
                chk = false;
                break;
            }
            if (getHash(1, i, i + minLen - 1) != hashCode[1][minLen]) {
                chk = false;
                break;
            }
        }
        if (chk) cout << len << " ";
    }
}