#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005
#define MAX_K 400

int n, q;
int arr[MAX_N];
int dp[MAX_N][MAX_K];

int Calc(int p, int k) {
    if (dp[p][k])
        return dp[p][k];

    int temp = p + arr[p] + k;
    if (temp > n) 
        return (dp[p][k] = 1);
    return (dp[p][k] = Calc(temp, k) + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    int __sqrt = sqrt(n);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (cin >> q; q--;) {
        int p, k;
        cin >> p >> k;

        if (k <= __sqrt) {
            cout << Calc(p, k) << "\n";
            continue;
        }

        int res = 0;
        while (++res) 
            if ((p = p + arr[p] + k) > n)
                break;
        cout << res << "\n";
    }
}