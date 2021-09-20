// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1003

int m, n;
bool a[MAX_N][MAX_N];
int h[MAX_N], L[MAX_N], R[MAX_N];
int res = 0;

void Calc(int row, bool t) {
    for (int i = 1; i <= n; i++)
        h[i] = (h[i] + 1) * (a[row][i] == t);
    
    stack<int> St;
    St.push(0);
    for (int i = 1; i <= n; i++) {
        while (St.size() > 1 && h[St.top()] >= h[i]) St.pop();
        L[i] = St.top();
        St.push(i);
    }

    St = stack<int> {};
    St.push(n + 1);
    for (int i = n; i; i--) {
        while (St.size() > 1 && h[St.top()] >= h[i]) St.pop();
        R[i] = St.top();
        St.push(i);
    }

    for (int i = 1; i <= n; i++) 
        if (R[i] - L[i] - 1 >= h[i])
            res = max(res, h[i]);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> m >> n;
    for (int i = 1; i <= m; i++) 
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    
    for (int i = 1; i <= m; i++)
        Calc(i, 0);
    for (int i = 1; i <= n; i++)
        h[i] = 0;
    for (int i = 1; i <= m; i++)
        Calc(i, 1);

    cout << res << "\n";
}