#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int p;
        cin >> p;
        int cnt = 0;
        for (int i = 2; i <= p - 1; i++) {
            if ((p - 1) % i == 0) {
                cout << i << " ";
                cnt++;
            }
            if (cnt == 2)
                break;
        }
        cout << "\n";
    }
}