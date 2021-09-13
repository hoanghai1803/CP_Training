// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define oo INT_MAX
#define MAX_N 10004
#define MAX_L 5003

int L, n;   
int w[MAX_N];

/* ==== Subtask 1: Brute-force, Generate bitmask ==== */
void Subtask_1() {
    for (int i = 0; i < n; i++) cin >> w[i];
    
    int res = +oo;
    for (int msk = 0; msk < (1 << n); msk++) {
        int box[] = {0, 0};
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int j = (msk >> i) & 1;
            if (box[j] + w[i] > L)
                cnt++, box[j] = w[i];
            else
                box[j] += w[i];
        }
        res = min(res, cnt + (box[0] > 0) + (box[1] > 0));
    }
    cout << res << "\n";
}

/* =============== Subtask 2: Ad HOC =============== */
void Subtask_2() {
    int w, Sum = 0;
    while (n--) {
        cin >> w;
        Sum += w;
    }
    cout << (Sum / L + (Sum % L > 0)) << "\n";
}

/* ======= Subtask 3,4,5: Dynamic Programming ======= */
const ii INF = ii(MAX_N, MAX_L);
ii dp[MAX_N][MAX_L];

template <class T> 
void Minimize(T& a, T b) {
    a = min(a, b);
}

void Subtask_5() {
    // Input
    for (int i = 1; i <= n; i++) cin >> w[i]; 
   
    // Init DP
    for (int i = 1; i <= n; i++)   
        for (int j = 0; j <= L; j++) dp[i][j] = INF;

    // At the beginning, we always open 2 boxes to use. If at the end of task, 
    // one of them has never be used, we will not count it in the result.
    dp[1][w[1]] = ii(2, 0); // Put the first item in the first box
    dp[1][0] = ii(2, w[1]); // Put the first item in the second box

    // DP: Using the optimization of dp[i] to optimize dp[i + 1]
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= L; j++) {
            if (dp[i][j] == INF) continue;

            /* Try to put the (i + 1)_th item in the first box */
            // Case 1: If the (i + 1)_th item can be put in the current first box
            if (j + w[i + 1] <= L) 
                Minimize(dp[i + 1][j + w[i + 1]], dp[i][j]);
            // Case 2: Close the current first box, and get a new one
            Minimize(dp[i + 1][w[i + 1]], ii(dp[i][j].first + 1, dp[i][j].second));

            /* Try to put the (i + 1)_th item in the second box */
            // Case 1: If the (i + 1)_th item can be put in the current second box
            if (dp[i][j].second + w[i + 1] <= L) 
                Minimize(dp[i + 1][j], ii(dp[i][j].first, dp[i][j].second + w[i + 1]));
            // Case 2: Close the current second box, and get a new one
            Minimize(dp[i + 1][j], ii(dp[i][j].first + 1, w[i + 1]));
        }

    int res = +oo;
    for (int i = 0; i <= L; i++) {
        // The case that only 2 boxes are opened at the beginning (no more boxes are opened)
        // and one of them has never be used, then the result is 1.
        if ((dp[n][i].first == 2) && (!i || !dp[n][i].second)) {
            res = 1;
            break;
        }
        Minimize(res, dp[n][i].first);
    }
    cout << res << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> L >> n;

    if (L > MAX_L) 
        Subtask_1();
    else if (n > MAX_N) 
        Subtask_2();
    else 
        Subtask_5();
}