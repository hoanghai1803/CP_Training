// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> lli;

vector<lli> Generate(vector<int> vec, int x) {
    vector<ll> vecSum;
    int __size = vec.size();

    for (int i = 0; i < (1 << __size); i++) {
        ll sum = 0;
        for (int j = 0; j < __size; j++)
            if ((i >> j) & 1) sum += vec[j];
        if (sum <= x)
            vecSum.push_back(sum);
    }
    sort(vecSum.begin(), vecSum.end());

    vector<lli> ret(1, lli(vecSum[0], 1));
    for (int i = 1; i < (int)vecSum.size(); i++) {
        if (vecSum[i] != ret[ret.size() - 1].first)
            ret.push_back(lli(vecSum[i], 1));
        else    
            ret.rbegin()->second++;
    }

    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    ll x;
    cin >> n >> x;
    vector<int> a(n / 2), b(n - n / 2);
    for (int& t: a) cin >> t;
    for (int& t: b) cin >> t;

    vector<lli> prefSet(Generate(a, x));
    vector<lli> suffSet(Generate(b, x));

    long long res = 0;
    for (int i = 0, j = suffSet.size() - 1; i < (int)prefSet.size(); i++) {
        while (j >= 0 && prefSet[i].first + suffSet[j].first > x) j--;
        if (j < 0) break;
        if (prefSet[i].first + suffSet[j].first == x) 
            res += 1LL * prefSet[i].second * suffSet[j].second;
    }

    cout << res << "\n";
}