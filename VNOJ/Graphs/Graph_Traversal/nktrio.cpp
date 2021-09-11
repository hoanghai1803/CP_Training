// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1003

int n;
int win[MAX_N][MAX_N], deg_out[MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> win[i][j];
            if (win[i][j]) deg_out[i]++;
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (!win[i][j] || deg_out[i] > deg_out[j]) continue;
            for (int k = 1; k <= n; k++)
                if (win[j][k] && win[k][i]) {
                    cout << i << " " << j << " " << k << "\n";
                    return 0;
                }
        }

    cout << "-1 -1 -1\n";
}