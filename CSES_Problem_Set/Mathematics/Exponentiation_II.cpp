// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MOD (int)(1e9 + 7)

int Pow(int a, int b, int m) {
    if (!b) return 1;
    int half = Pow(a, b / 2, m);
    if (b & 1) 
        return (1LL * half * half % (MOD - m)) * a % (MOD - m);
    return 1LL * half * half % (MOD - m);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, a, b, c;
    for (cin >> n; n--;) {
        cin >> a >> b >> c;
        cout << Pow(a, Pow(b, c, 1), 0) << "\n";
    }
}