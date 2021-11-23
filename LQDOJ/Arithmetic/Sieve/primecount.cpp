// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define SQRT_N 32000

bool isPrime[SQRT_N];
vector<int> primes;

void sieve() {
    for (int i = 2; i < SQRT_N; i++)
        isPrime[i] = true;

    for (int i = 2; i < SQRT_N; i++)
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < SQRT_N; j += i)
                isPrime[j] = false;
        }
}

void calc(int l, int r) {
    vector<bool> chk(r - l + 1, true);
    for (int p: primes)
        for (int i = max(p * p, (l + p - 1) / p * p); i <= r; i += p)
            chk[i - l] = false;
    cout << count(chk.begin(), chk.end(), true) - (l == 1) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    sieve();
    int t, l, r;
    for (cin >> t; t--;) {
        cin >> l >> r;
        calc(l, r);
    }
}