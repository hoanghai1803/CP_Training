// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005
#define LOG_N 22

int n, q;
int a[MAX_N], M[MAX_N][LOG_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // RMQ Init
    for (int i = 1; i <= n; i++)
        M[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) 
        for (int i = 1; i + (1 << j) - 1 <= n; i++) 
            M[i][j] = min(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);

    // Queries
    for (int l, r; q--;) {
        cin >> l >> r;
        int k = floor(log2(r - l + 1));
        cout << min(M[l][k], M[r - (1 << k) + 1][k]) << "\n";
    }
}