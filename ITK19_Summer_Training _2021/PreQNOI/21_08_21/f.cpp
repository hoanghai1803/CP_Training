#include <bits/stdc++.h>

using namespace std;

#define abs(x) ((x>0)?(x):-(x))
#define MAX_N 5555

int n;
int a[MAX_N];
int finishAt[MAX_N], startAt[MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        finishAt[i] = 1;
        for (int j = i - 1; j >= 1; j--) 
            if (abs(a[i] - a[j]) == 1 || a[i] % 7 == a[j] % 7)
                finishAt[i] = max(finishAt[i], finishAt[j] + 1);
    }

    for (int i = n; i >= 1; i--) {
        startAt[i] = 1;
        for (int j = i + 1; j <= n; j++) 
            if (abs(a[i] - a[j]) == 1 || a[i] % 7 == a[j] % 7)
                startAt[i] = max(startAt[i], startAt[j] + 1);
    }

    int res = 0;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            res = max(res, finishAt[i] + startAt[j]);
    cout << res << "\n";
}