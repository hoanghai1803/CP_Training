// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

long long Calc(vector<int> vec, int n, int U) {
    unordered_map<int, int> mark;
    int cnt = 0;
    long long ret = 0;

    for (int L = 0, R = 0; L <= R && R < n; L++) {
        for (; R < n && cnt <= U; R++) {
            if (mark[vec[R]]) {
                mark[vec[R]]++;
                ret += R - L + 1;
            } else {
                if (cnt + 1 > U)
                    break;
                mark[vec[R]]++, cnt++;
                ret += R - L + 1;
            }
        }
        if (!--mark[vec[L]])
            cnt--;
    }

    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, l, u;
    cin >> n >> l >> u;
    vector<int> vec(n);
    for (int& x: vec) 
        cin >> x;
    cout << Calc(vec, n, u) - Calc(vec, n, l - 1) << "\n";
}