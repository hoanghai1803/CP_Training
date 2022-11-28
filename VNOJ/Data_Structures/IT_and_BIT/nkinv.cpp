// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 60004

int n, a, res = 0;
int bit[MAX_N];

void update(int p) {
    for (int i = p; i < MAX_N; i += i & -i) bit[i]++;
}

void getVal(int p) {
    for (int i = p; i; i -= i & -i) res += bit[i];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        getVal(MAX_N - a - 1);
        update(MAX_N - a);
    }
    cout << res << "\n";
}