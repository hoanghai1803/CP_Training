// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005

int n;
long long res = 1;
int x[MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> x[i];
    sort(x, x + n);
    for (int i = 0; i < n && x[i] <= res; i++)
        res += x[i];
    cout << res << "\n";
}