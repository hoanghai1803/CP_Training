// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define abs(x) ((x)>0?(x):-(x))

#define MAX_N 555

int n, q;
int a[MAX_N][MAX_N], S[MAX_N][MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if ((i + j) & 1) a[i][j] *= -1;
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a[i][j];
        }
    
    for (cin >> q; q--;) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << abs(S[u][v] - S[u][y - 1] - S[x - 1][v] + S[x - 1][y - 1]) << "\n";
    }
}