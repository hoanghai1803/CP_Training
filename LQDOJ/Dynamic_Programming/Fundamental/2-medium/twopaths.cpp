// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define oo 1e9
#define MAX_N 222

int n, m;
int score[MAX_N][MAX_N];
int dp[2 * MAX_N][MAX_N][MAX_N]; 

bool valid(int column) {
    return column > 0 && column <= m;
}

void Solve() {
    // Initialization
    for (int s = 0; s < n + m; s++)
        for (int r1 = 0; r1 <= n; r1++) 
            for (int r2 = 0; r2 <= n; r2++) dp[s][r1][r2] = -oo;
    dp[0][1][1] = 0;

    // DP
    for (int s = 1; s < n + m - 1; s++)
        for (int r1 = 1; r1 < n; r1++)
            for (int r2 = r1 + 1; r2 <= n; r2++) {
                int c1 = s + 2 - r1, c2 = s + 2 - r2;
                if (!valid(c1) || !valid(c2)) continue;
                for (int i = 0; i < 2; i++)
                    for (int j = 0; j < 2; j++) {
                        if (dp[s - 1][r1 - i][r2 - j] == -oo) continue;
                        dp[s][r1][r2] = max(dp[s][r1][r2], dp[s - 1][r1 - i][r2 - j] + score[r1][c1] + score[r2][c2]);
                    }
            }       
                
    cout << dp[n + m - 3][n - 1][n] << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> n >> m;
    for (int r = 1; r <= n; r++)
        for (int c = 1; c <= m; c++)
            cin >> score[r][c];
    Solve();
}