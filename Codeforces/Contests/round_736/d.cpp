#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005

int t, n;
long long a[MAX_N];
long long prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int cnt[100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) 
            cin >> a[i];

        int res = 0;
        for (int p = 0; p < 10; p++) {
            for (int i = 0; i < prime[p]; i++)
                cnt[i] = 0;
            for (int i = 1; i <= n; i++)
                cnt[a[i] % prime[p]]++;
            for (int i = 0; i < prime[p]; i++)
                res = max(res, cnt[i]);
            cout << prime[p]  << " " << res << "\n";
        }
        cout << res << "\n";
    }
}