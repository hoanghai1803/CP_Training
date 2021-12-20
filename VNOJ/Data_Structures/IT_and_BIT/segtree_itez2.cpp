#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

int n, q;
int a[MAX_N];
long long bit[MAX_N];

void Update(int p, int val) {
    for (int i = p; i <= n; i += i & -i) 
        bit[i] += val;
}

long long getSum(int p) {
    long long ret = 0;
    for (int i = p; i; i -= i & -i)
        ret += bit[i];
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> n >> q; q--;) {
        int t, p, x, l, r;
        cin >> t;
        if (t == 1) {
            cin >> p >> x;
            Update(p, x - a[p]);
            a[p] = x;
            continue;
        }
        cin >> l >> r;
        cout << getSum(r) - getSum(l - 1) << "\n";
    }
}