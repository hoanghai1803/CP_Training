#include <bits/stdc++.h>

using namespace std;

#define abs(x) ((x>0)?(x):(-x))
typedef pair<int, int> ii;

#define MAX_N 100005

int n, d, k;
int c[MAX_N], dp[MAX_N];
ii gift[MAX_N];

bool operator < (ii a, ii b) {
    if (a.first < b.first && a.second < b.second)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> d;
    for (int i = 0; i < 2 * n; i++)
        cin >> c[i];
    for (int i = 0; i < 2 * n; i++)
        for (int j = i + 1; j < 2 * n; j++) 
            if (abs(c[i] - c[j]) <= d)
                gift[++k] = ii(i, j);

    for (int i = 1; i <= k; i++) {
        dp[i] = 1;
        for (int j = k - 1; j > 0; j++)
            if (gift[j] < gift[i])
                dp[i] = max(dp[i], dp[j] + 1);
    }

}