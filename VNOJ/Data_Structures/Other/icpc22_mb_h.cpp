// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    multiset<long long> left_pq, right_pq;

    auto balance = [&]() {
        if (left_pq.size() < right_pq.size()) {
            left_pq.insert(*right_pq.begin());
            right_pq.erase(right_pq.begin());
        }

        if (left_pq.size() > right_pq.size() + 1) {
            right_pq.insert(*left_pq.rbegin());
            left_pq.erase(--left_pq.end());
        }
    };

    long long q, num;
    string type;
    for (cin >> q; q--;) {
        cin >> type;

        if (type == "IN") {
            cin >> num;
            if (left_pq.empty() || num < *left_pq.rbegin())
                left_pq.insert(num);
            else
                right_pq.insert(num);
            balance();
        }

        if (type == "OUT") {
            cin >> num;
            if (num <= *left_pq.rbegin())
                left_pq.erase(left_pq.lower_bound(num));
            else
                right_pq.erase(right_pq.lower_bound(num));
            balance();
        }

        if (type == "MEDIAN") {
            if (left_pq.size() == right_pq.size())
                cout << (*left_pq.rbegin() + *right_pq.begin()) / 2.0 << "\n";
            else
                cout << *left_pq.rbegin() << "\n";
        }
    }
}