// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1e3 + 3;
const int MOD[] = {(int)1e9 + 7, (int)1e9 + 33, (int)1e9 + 93, (int)1e9 + 103, (int)1e9 + 181};
const int BASE = 10;

int n, q;
ll hashNum[MAX_N][5];

ll Calc(int x, int y, char c, int k) {
    if (c == '+') return (hashNum[x][k] + hashNum[y][k]) % MOD[k];
    if (c == '-') return (hashNum[x][k] - hashNum[y][k] + MOD[k]) % MOD[k];
    return hashNum[x][k] * hashNum[y][k] % MOD[k];
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;
        int sign = 1;
        for (int j = 0; j < (int)num.length(); j++) {
            if (num[j] == '-') {
                sign = -1;
                continue;
            }
            for (int k = 0; k < 5; k++)
                hashNum[i][k] = (hashNum[i][k] * BASE + num[j] - '0') % MOD[k];
        }
        for (int k = 0; k < 5; k++)
            hashNum[i][k] = (hashNum[i][k] * sign + MOD[k]) % MOD[k];
    }

    while (q--) {
        int x1, y1, x2, y2;
        char c1, c2;
        cin >> x1 >> y1 >> c1 >> x2 >> y2 >> c2;
        int chk = true;
        for (int k = 0; k < 5; k++) {
            ll lhs = Calc(x1, y1, c1, k);
            ll rhs = Calc(x2, y2, c2, k);
            if (lhs != rhs) {
                chk = false;
                break;
            }
        }
        cout << (chk ? "YES\n" : "NO\n");
    }
}
