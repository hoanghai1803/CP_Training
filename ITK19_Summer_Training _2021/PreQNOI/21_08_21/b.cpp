#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k, a;
    long long sum = 0, week = 0;
    queue<int> Q;

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        week += a, Q.push(a);
        if (Q.size() > k) 
            week -= Q.front(), Q.pop();
        if (Q.size() == k)
            sum += week;
    }
    
    cout << fixed << setprecision(7) << (double)sum / (n - k + 1) << "\n";
}