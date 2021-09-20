// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10004

int k, n;
vector<int> adj[MAX_N];
int res = 0;

int Calc(int u) {
    int children = 1;
    for (int v: adj[u]) children += Calc(v);
    if (children >= k) {
        res++;
        return 0;
    } else {
        return children;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> k >> n;
    for (int u = 2, v; u <= n; u++) {
        cin >> v;
        adj[v].push_back(u);
    }

    Calc(1);
    cout << res << "\n";
}