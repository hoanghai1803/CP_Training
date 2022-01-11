#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string e, g;
        cin >> e;
        cin >> g;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (g[i] == '0')
                continue;
            if (i > 0 && e[i - 1] == '1') {
                res++;
                continue;
            }
            if (e[i] == '0') {
                res++;
                continue;
            }
            if (e[i + 1] == '1') {
                res++, e[i + 1] = '2';
                continue;
            }
        }
        cout << res << "\n";
    }
}