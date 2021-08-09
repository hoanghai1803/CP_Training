#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
#define MAX_N 1000006

int n, k, q;
int fact[MAX_N], powFact[MAX_N];

int pow(int a, int n) {
    if (n == 1)
        return a;
    int half = pow(a, n / 2);
    if (n & 1)
        return (1LL * half * half % MOD) * a % MOD;
    return 1LL * half * half % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++)
        fact[i] = 1LL * fact[i - 1] * i % MOD;

    powFact[0] = 1;
    for (int i = 1; i < MAX_N; i++)
        powFact[i] = 1LL * powFact[i - 1] * pow(i, MOD - 2) % MOD;

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    
    int res = fact[s.length()];
    int cnt = 1;
    for (int i = 1; i < s.length(); i++)
        if (s[i] != s[i - 1])
            res = 1LL * res * powFact[cnt] % MOD, cnt = 1;
        else 
            cnt++;
    res = 1LL * res * powFact[cnt] % MOD, cnt = 1;
    cout << res;
}