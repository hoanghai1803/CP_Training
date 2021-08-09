#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define MAX_V 1000006

int n;
int numPrimes;
int a[MAX_N], primes[MAX_N];
bool isPrime[MAX_V];
map<int, int> cnt;

void sieve() {
    for(int i = 0; i < MAX_V; i++) 
        isPrime[i] = true;

    for (int p = 2; p * p < MAX_V; p++) 
        if (isPrime[p]) 
            for (int i = p * p; i < MAX_V; i += p)
                isPrime[i] = false;

    for (int i = 2; i < MAX_V; i++)
        if (isPrime[i])
            primes[++numPrimes] = i;
}

int factorize(int x) {
    int ret = 1;
    for (int i = 1; i <= numPrimes; i++) 
        if (!(x % primes[i])) {
            ret *= primes[i];
            while (!(x % primes[i]))
                x /= primes[i];
            if (x == 1)
                break;
        }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = factorize(a[i]);
        cout << a[i] << endl;
        if (cnt[a[i]]) 
            cnt[a[i]]++;
        else 
            cnt[a[i]] = 1;
    }
    cout << endl;

    long long res = 0;
    for (int i = 0; i < n; i++)
        res += n - cnt[a[i]];
    cout << res / 2;
}