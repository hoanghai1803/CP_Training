// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, m;
vector<ii> stones;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // Initialization
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int w, v, a;
        cin >> w >> v >> a;
        for (int j = 0; (1 << j) < a; j++) {
            int p = 1 << j;
            stones.push_back(ii(p * w, p * v));
            a -= p;
        }
        if (a) stones.push_back(ii(a * w, a * v)); 
    }   

    // Dynamic Programming
    vector<int> dp(m + 1, 0), F(m + 1, 0);
    
    for (ii stone: stones) {
        for (int w = 0; w <= m; w++)
            if (stone.first <= w)
                dp[w] = max(dp[w], F[w - stone.first] +  stone.second);
        for (int w = 0; w <= m; w++)
            F[w] = dp[w];
    }

    // Print out result
    int res = 0;
    for (int w = 0; w <= m; w++)
        res = max(res, dp[w]);

    cout << res << "\n";
}