#include <bits/stdc++.h>

using namespace std;

#define MAX_N 22

int n;
int p[MAX_N];
bool choose[MAX_N];
long long res = 1e15;

void Try(int i) {
    if (i == n) {
        long long diff = 0;
        for (int i = 0; i < n; i++)
            diff += (choose[i] ? 1 : -1) * p[i];
        res = min(res, abs(diff));
        return;
    }

    Try(i + 1);
    choose[i] = true;
    Try(i + 1);
    choose[i] = false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    Try(0);
    cout << res << "\n";
}