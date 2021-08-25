#include <bits/stdc++.h>

using namespace std;

#define abs(x) ((x>0)?(x):-(x))
#define oo INT_MAX

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int& x: a) 
        cin >> x;
    for (int& x: b) {
        cin >> x;
        x *= -1;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int res = +oo;
    for (int i = 0, j = 0; i < n; i++) {
        for (; j < n; j++)
            if (b[j] > a[i])
                break;

        if (!j) {
            res = abs(a[i] - b[j]);
            continue;
        }
        if (j == n) {
            res = min(res, abs(a[i] - b[j - 1]));
            break;
        }
        res = min(res, min(abs(a[i] - b[j]), abs(a[i] - b[j - 1])));
    }

    cout << res << "\n";
}