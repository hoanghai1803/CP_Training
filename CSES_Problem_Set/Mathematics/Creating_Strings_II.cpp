// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000006
#define MOD (int)(1e9 + 7)

string str;
int cnt[30];
int fact[MAX_N], iFact[MAX_N];

int Pow(int a, int n) {
    if (!n) return 1;
    int half = Pow(a, n / 2);
    if (n & 1)
        return (1LL * half * half % MOD) * a % MOD;
    return 1LL * half * half % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(false); 

    // Pre-compute factorial 0 -> MAX_N
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++)
        fact[i] = (1LL * fact[i - 1] * i) % MOD;

    // Pre-compute inverse factorial 0 -> MAX_N
    iFact[MAX_N - 1] = Pow(fact[MAX_N - 1], MOD - 2);
    for (int i = MAX_N - 1; i; i--)
        iFact[i - 1] = (1LL * iFact[i] * i) % MOD;

    cin >> str;
    for (int i = 0; i < (int)str.size(); i++) 
        cnt[str[i] - 'a']++;
    
    int res = fact[str.size()];
    for (int i = 0; i < 26; i++)
        res = 1LL * res * iFact[cnt[i]] % MOD;
    
    cout << res << "\n";
}