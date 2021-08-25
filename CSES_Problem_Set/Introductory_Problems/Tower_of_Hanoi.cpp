// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

void Solve(int n, int st1, int st2, int st3) {
    if (n == 1) {
        cout << st1 << " " << st3 << "\n";
        return;
    }

    Solve(n - 1, st1, st3, st2);
    Solve(1, st1, st2, st3);
    Solve(n - 1, st2, st1, st3);
}

int main() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    Solve(n, 1, 2, 3);
}