// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5005;
const int MOD[] = {(int)(1e9 + 7), (int)(1e9 + 409)};
const int BASE = 26;

int n;
string str;
long long hashCode[2][MAX_N], Pow[2][MAX_N];

long long getHash(int id, int l, int r) {
    long long diff = hashCode[id][r] - hashCode[id][l - 1] * Pow[id][r - l + 1];
    return (diff < 0 ? (diff + 1LL * MOD[id] * MOD[id]) % MOD[id] : diff);
}

bool Check(int len) {
    for (int i = 0; i < n; i++)
        for (int j = i + len; j < n; j++) {
            if (j + len - 1 >= n) break;
            if (getHash(0, i, i + len - 1) != getHash(0, j, j + len - 1))
                continue;
            if (getHash(1, i, i + len - 1) != getHash(1, j, j + len - 1))
                continue;    
            return true;
        }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    cin >> str;

    for (int k = 0; k < 2; k++)
        for (int i = 0; i < n; i++) {
            hashCode[k][i] = i ? (hashCode[k][i - 1] * BASE + str[i] - 'a') % MOD[k] : str[i] - 'a';
            Pow[k][i] = i ? Pow[k][i - 1] * BASE % MOD[k] : 1; 
        }
  
    // Binary Search
    int res = 0, L = 1, R = n;
    while (true) {
        int M = (L + R) >> 1;
        if (L == M || R == M) {
            if (Check(R)) {
                res = R;
                break;
            }
            if (Check(L)) res = L;
            break;
        }

        if (Check(M)) L = M;
        else R = M;
    }

    cout << res << "\n";
}
