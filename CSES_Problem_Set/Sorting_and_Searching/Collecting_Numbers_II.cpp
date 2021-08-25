// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005

int n, m;
int x[MAX_N];
bool isStart[MAX_N];
int res;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        if (!isStart[x[i] - 1]) {
            res++;
            isStart[x[i]] = true;
        }
    }

    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        swap(a, b);
        cout << res << "\n";
    }
}