// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MOD (int)(1e9 + 7)

int Pow(int a, int b) {
    if (!b) return 1;
    int half = Pow(a, b / 2);
    if (b & 1) 
        return (1LL * half * half % MOD) * a % MOD;
    return 1LL * half * half % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, a, b;
    for (cin >> n; n--;) {
        cin >> a >> b;
        cout << Pow(a, b) << "\n";
    }
}