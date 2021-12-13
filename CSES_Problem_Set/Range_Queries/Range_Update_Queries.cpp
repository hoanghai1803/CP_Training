// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MAX_N 200005

int n, q;
int64 arr[MAX_N], diff[MAX_N], bit[MAX_N];

void update(int p, int val) {
    for (int i = p; i <= n; i += i & -i) 
        bit[i] += val;
}

long long getVal(int p) {
    int64 ret = 0;
    for (int i = p; i; i -= i & -i)
        ret += bit[i];
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        diff[i] = arr[i] - arr[i - 1];
        update(i, diff[i]);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, v;
            cin >> a >> b >> v;
            update(a, v);
            update(b + 1, -v);
            diff[a] += v, diff[b + 1] -= v;
        } else {
            int p;
            cin >> p;
            cout << getVal(p) << "\n";
        }
    }
}