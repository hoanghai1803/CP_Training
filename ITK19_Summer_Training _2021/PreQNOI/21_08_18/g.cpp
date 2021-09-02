#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[111][111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        if (!k) 
            break;
        a[i][i] = 1;
        if (!(--k))
            break;
        for (int j = i + 1; j <= n; j++) {
            if (k == 1) {
                k--;
                a[i + 1][i + 1] = 1;
                break;
            }
            a[i][j] = a[j][i] = 1;
            k -= 2;
            if (!k)
                break;
        }
    }

    if (k) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}