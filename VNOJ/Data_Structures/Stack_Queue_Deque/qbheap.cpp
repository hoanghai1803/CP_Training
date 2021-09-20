// Author: __BruteForcce__
#include <bits/stdc++.h>

using namespace std;

#define K 15000

int main() {
    // freopen("qbheap.inp", "r", stdin);
    // freopen("qbheap.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(false);

    string qu;
    priority_queue<int> Heap;

    while (cin >> qu) {
        if (qu[0] == '-') {
            if(Heap.empty()) continue;
            int temp = Heap.top();
            while(Heap.size() && Heap.top() == temp) Heap.pop();
            continue;
        }

        if (Heap.size() >= K) continue;
        int num = 0;
        for (int i = 1; i < (int)qu.length(); i++)
            num = num * 10 + (qu[i] - '0');
        Heap.push(num);
    }

    vector<int> res;
    while (Heap.size()) {
        if (res.empty() || Heap.top() != *res.rbegin()) 
            res.push_back(Heap.top());
        Heap.pop();
    }

    cout << res.size() << "\n";
    for (int x: res) cout << x << "\n";
}