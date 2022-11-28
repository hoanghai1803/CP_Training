// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MAX_N 10004
#define MAX_P 30004

int n, bit[MAX_P];
pii a[MAX_N];

void update(int p, int v) {
    for (int i = p; i < MAX_P; i += i & -i) 
        bit[i] = max(bit[i], v);
}

int getMax(int p) {
    int ret = 0;
    for (int i = p; i; i -= i & -i)
        ret = max(ret, bit[i]);
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i].second >> a[i].first;
    sort(a + 1, a + 1 + n);
    
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int dp = getMax(a[i].second) + a[i].first - a[i].second;
        update(a[i].first, dp);
        res = max(res, dp);
    }

    cout << res << "\n";
}