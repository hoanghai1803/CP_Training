// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 300000

struct Data {
    int id, l, r, val;

    bool operator < (const Data& other) const {
        return (val > other.val || (val == other.val && id > other.id));
    }
};

int n, q;
Data a[MAX_N]; 
int res[MAX_N], bit[MAX_N];

void Update(int p) {
    for (; p <= n; p += p & -p) bit[p]++;
}

int getSum(int p) {
    int ret = 0;
    for (; p; p -= p & -p) ret += bit[p];
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        a[i] = {0, i, i, val};
    }

    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> a[n + i].l >> a[n + i].r >> a[n + i].val;
        a[n + i].id = i;
    }

    sort (a + 1, a + 1 + n + q);

    for (int i = 1; i <= n + q; i++) 
        if (a[i].id) 
            res[a[i].id] = getSum(a[i].r) - getSum(a[i].l - 1);
        else 
            Update(a[i].l);
    
    for (int i = 1; i <= q; i++) 
        cout << res[i] << "\n";
}