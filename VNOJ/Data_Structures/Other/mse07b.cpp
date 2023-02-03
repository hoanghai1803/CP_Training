// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int id;
int p, k;

set<pair<int, int>> Queue;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    while(1) {
        cin >> id;
        if(!id) return 0;
        if(id == 1) {
            cin >> k >> p;
            Queue.insert({p, k});
        }
        if(id == 2) {
            if(!Queue.size()) {
                cout << "0\n";
                continue;
            }
            p = (*Queue.rbegin()).first, k = (*Queue.rbegin()).second;
            cout << k << "\n";
            Queue.erase({p,k});
        }
        if(id == 3) {
            if(!Queue.size()) {
                cout << "0\n";
                continue;
            }
            p = (*Queue.begin()).first, k = (*Queue.begin()).second;
            cout << k << "\n";
            Queue.erase({p, k});
        }
    }
}