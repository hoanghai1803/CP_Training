// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int m, n, k;
    cin >> m >> n >> k;
    vector<int> a(m), b(n);
    for (int& x: a) cin >> x;
    for (int& y: b) cin >> y;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    priority_queue<int> Pq;
    for (int x: a) 
        for (int y: b) {
            int sum = x + y;
            if ((int)Pq.size() == k && sum > Pq.top()) break;
            if ((int)Pq.size() == k) Pq.pop();
            Pq.push(sum);
        }

    vector<int> res;
    while (Pq.size()) res.push_back(Pq.top()), Pq.pop();
    reverse(res.begin(), res.end());
    for (int sum: res) cout << sum << "\n";
}