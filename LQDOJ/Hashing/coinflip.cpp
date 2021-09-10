// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int64 oo = 1e18;
const int MAX_N = 1e4 + 4;
const int MAX_M = 30;

int n, m;
int64 Hash[MAX_N];
int64 btn[MAX_M];
int64 sumXor[(1 << 25) + 3];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();

    cin >> n >> m;
    // Generate hash code
    mt19937_64 rng(seed);
    for (int i = 1; i <= n; i++) Hash[i] = rng() % oo;
    // Shuffle to make sure
    mt19937_64 sf(seed);
    shuffle(Hash + 1, Hash + 1 + n, sf);

    int64 target = 0;
    for (int i = 1, stt; i <= n; i++) {
        cin >> stt;
        if (!stt) target ^= Hash[i];
    }

    for (int i = 1, len, idx; i <= m; i++) 
        for (cin >> len; len--;) {
            cin >> idx;
            btn[i] ^= Hash[idx]; 
        }

    for (int msk = 0; msk < (1 << m); msk++) {
        if (msk) {
            int idx = __builtin_ctz(msk); // Count of trailing zero
            sumXor[msk] = sumXor[msk ^ (1 << idx)] ^ btn[idx + 1];
        }
        if (sumXor[msk] == target) {
            cout << __builtin_popcount(msk) << "\n";
            for (int i = 1; i <= m; i++)
                if ((msk >> (i - 1)) & 1) cout << i << " ";
            break;
        }
    }
}
