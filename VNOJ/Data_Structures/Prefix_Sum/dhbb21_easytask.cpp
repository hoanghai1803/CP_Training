// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MAX_N 1000006
#define oo LLONG_MAX

bool isPrime[MAX_N];

void sieve() {
    for (int i = 2; i < MAX_N; i++) 
        isPrime[i] = true;
    
    for (int i = 2; i * i < MAX_N; i++)
        if (isPrime[i])
            for (int j = i * i; j < MAX_N; j += i)
                isPrime[j] = false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    sieve();

    int n, val;
    int64 pref_sum = 0, min_pref = +oo, res = -oo;    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        if (isPrime[i]) min_pref = min(min_pref, pref_sum);
        pref_sum += val;
        if (isPrime[i] && min_pref != +oo) 
            res = max(res, pref_sum - min_pref);
    }
    cout << res << "\n";
}