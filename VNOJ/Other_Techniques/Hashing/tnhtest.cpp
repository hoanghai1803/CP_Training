// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    string a, b;
    int c;
    cin >> a >> b;
    cin >> c;
    
    int num = 0, res = 1;
    for (int i = 0; i < (int)a.length(); i++)
        num = (1LL * num * 10 + a[i] - '0') % c;
    for (int i = 0; i < (int)b.length(); i++) {
        int temp = 1;
        for (int j = 0; j < 10; j++) 
            temp = 1LL * temp * res % c;
        res = temp, temp = 1;
        for (int j = 0; j < b[i] - '0'; j++)
            temp = 1LL * temp * num % c;
        res = 1LL * res * temp % c;
    }

    cout << res << "\n";
}
