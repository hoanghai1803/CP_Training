// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define oo LLONG_MAX

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int64> dp(n + 1);
    priority_queue<pair<int64, int>> Heap; // MAX HEAP

    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        dp[i] = val;
        if (Heap.size()) {
            while (Heap.size() && Heap.top().second < i - k) Heap.pop();
            if (Heap.size()) dp[i] += Heap.top().first;
        } 
        if (dp[i] > 0) Heap.push({dp[i], i});
    }

    int64 res = -oo;
    for (int i = 1; i <= n; i++)
        res = max(res, dp[i]);
    cout << max(res, 0LL) << "\n";
}