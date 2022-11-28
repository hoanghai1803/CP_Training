// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MAX_N 1000006

int t, m, n;
bool is_prime[MAX_N];
int prime_base[MAX_N], sign[MAX_N];
vector<int> bases;

void sieve() {
    for (int i = 2; i < MAX_N; i++) is_prime[i] = prime_base[i] = 1;
    memset(sign, -1, sizeof(sign));

    for (int i = 2; i < MAX_N; i++)
        if (is_prime[i]) {
            prime_base[i] = i, sign[i] *= -1;
            for (int j = 2 * i; j < MAX_N; j += i)
                is_prime[j] = false, prime_base[j] *= i, sign[j] *= -1;
        }

    for (int i = 2; i < MAX_N; i++)
        if (prime_base[i] == i) bases.push_back(i);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    sieve();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> m >> n;
        if (m > n) swap(m, n);
        int64 pairs = 0;
        for (int x : bases) {
            if (x > m) break;
            pairs += 1LL * sign[x] * (m / x) * (n / x);
        }
        cout << "Case " << i << ": "
             << 1LL * m * n - pairs + (m != 0) + (n != 0) << "\n";
    }
}