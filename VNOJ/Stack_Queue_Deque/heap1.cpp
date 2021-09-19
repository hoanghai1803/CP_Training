// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t, n, a;
    priority_queue<int, vector<int>, greater<int> > Heap;

    for (cin >> t; t--;) {
        while (Heap.size()) Heap.pop();
        for (cin >> n; n--;) {
            cin >> a;
            Heap.push(a);
        }

        long long res = 0;
        while (Heap.size() > 1) {
            int x = Heap.top();
            Heap.pop();
            int y = Heap.top();
            Heap.pop();
            res += x + y;
            Heap.push(x + y);
        }

        cout << res << "\n";
    }
}