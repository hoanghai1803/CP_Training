#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    bool chk = false;
    cin >> n >> k;
    vector<int> res;
    for (int i = 2; i <= n; i++) {
        while (!(n % i)) {
            res.push_back(i);
            n /= i;
            if (res.size() == k) {
                res[res.size() - 1] *= n;
                chk = true;
                break;
            }
        }
        if (chk)
            break;
    }

    if (chk) 
        for (auto ele: res)
            cout << ele << " ";
    else 
        cout << "-1\n";
}