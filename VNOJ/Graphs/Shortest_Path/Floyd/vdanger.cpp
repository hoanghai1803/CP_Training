// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 111
#define MAX_M 11111

int n, m;
int a[MAX_M];
int c[MAX_N][MAX_N];

void minimize(int& a, int b) {
    if (a > b) a = b;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // Init
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            cin >> c[u][v];

    // Floyd
    for (int k = 1; k <= n; k++)
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++) 
                minimize(c[u][v], c[u][k] + c[k][v]);

    // Solve
    long long res = 0;
    for (int i = 1; i < m; i++) res += c[a[i]][a[i + 1]];
    cout << res << "\n";
}