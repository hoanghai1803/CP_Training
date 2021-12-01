// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_VAL 1000006

int n, res;
int exist[MAX_VAL];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        exist[x]++;
    }

    for (int i = 1; i < MAX_VAL; i++) {
        int cnt = 0;
        for (int j = i; j < MAX_VAL; j += i)
            cnt += exist[j];
        if (cnt > 1) res = i;
    }

    cout << res << "\n";
}