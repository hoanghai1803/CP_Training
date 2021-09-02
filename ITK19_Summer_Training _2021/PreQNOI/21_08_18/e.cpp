#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
#define MAX_N 100005

int n, a;
int cnt[MAX_N];
int pow_2[MAX_N];
int res = 0;

int pow(int a, int n) {
    if (!n) 
        return 1;
    int half = pow(a, n / 2);
    if (n & 1)
        return (1LL * half * half % MOD) * a % MOD;
    return 1LL * half * half % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    for (int i = 0; i < MAX_N; i++)
        pow_2[i] = pow(2, i);

    for (cin >> n; n--;) {
        cin >> a;
        vector<int> primes;
        for (int i = 2; i * i <= a; i++) 
            if (!(a % i)) {
                primes.push_back(i);
                while(!(a % i)) a /= i;
            }
        if (a > 1)
            primes.push_back(a);

        int __size = primes.size();
        for (int i = 0; i < (1 << __size); i++) {
            int num = 1;
            for (int j = 0; j < __size; j++)
                if ((i >> j) & 1) num *= primes[j];
            if (__builtin_popcount(i) & 1) {
                res = (res + MOD - pow_2[cnt[num]]) % MOD;
            } else {
                res = (res + pow_2[cnt[num]]) % MOD;
            }
            cnt[num]++;
        }
    }

    cout << res << "\n";
}