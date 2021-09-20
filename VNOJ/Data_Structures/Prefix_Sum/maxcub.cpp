// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define oo LLONG_MAX
#define MAX_N 33

long long S[MAX_N][MAX_N][MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t, n;
    for (cin >> t; t--;) {
        cin >> n;
        long long res = -oo;
        for (int x = 1; x <= n; x++)
            for (int y = 1; y <= n; y++)
                for (int z = 1; z <= n; z++) {
                    // Calculating prefix Sum 3D
                    cin >> S[x][y][z];
                    S[x][y][z] += S[x - 1][y][z] + S[x][y - 1][z] + S[x][y][z - 1];
                    S[x][y][z] -= S[x - 1][y - 1][z] + S[x - 1][y][z - 1] + S[x][y - 1][z - 1];
                    S[x][y][z] += S[x - 1][y - 1][z - 1];

                    // Updating result for each k-size cube
                    int minSize = min(x, min(y, z));
                    for (int k = 1; k <= minSize; k++) {
                        long long sum = S[x][y][z];
                        sum -= S[x - k][y][z] + S[x][y - k][z] + S[x][y][z - k];
                        sum += S[x - k][y - k][z] + S[x - k][y][z - k] + S[x][y - k][z - k];
                        sum -= S[x - k][y - k][z - k];
                        res = max(res, sum);
                    }
                }
        cout << res << "\n";
    }
}