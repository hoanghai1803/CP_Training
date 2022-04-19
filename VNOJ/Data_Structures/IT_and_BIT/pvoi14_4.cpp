// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 50005

int n;
int a[MAX_N], v[MAX_N];
int dp[MAX_N][5], bit[5][MAX_N];
unordered_map<int, int> um;

void update(int id, int p, int val) {
    if (id & 1) {
        for (; p <= n; p += p & -p)
            bit[id][p] = max(bit[id][p], val);
    } else {
        for (; p; p -= p & -p) 
            bit[id][p] = max(bit[id][p], val);
    }
}

int get(int id, int p) {
    int ret = 0;
    if (id & 1) {
        for (p--; p > 0; p -= p & -p)
            ret = max(ret, bit[id][p]);
    } else {
        for (p++; p <= n; p += p & -p)
            ret = max(ret, bit[id][p]);
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], v[i] = a[i];

    sort(v + 1, v + 1 + n);
    int len = unique(v + 1, v + 1 + n) - v - 1;
    for (int i = 1; i <= len; i++) um[v[i]] = i;

    for (int i = 1; i <= n; i++)
        for (int id = 1; id <= 4; id++) {
            dp[i][id] = get(id, um[a[i]]) + 1;
            if (id > 1 && dp[i][id] < id + 1) dp[i][id] = 0;
            update(id, um[a[i]], dp[i][id]);
            if (id > 1 && dp[i][id - 1] >= id) update(id, um[a[i]], dp[i][id - 1]);
        }

    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, dp[i][4]);
    cout << res << "\n";
}