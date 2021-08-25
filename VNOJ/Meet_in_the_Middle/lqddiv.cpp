// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> lli;

#define abs(x) ((x)>0?(x):-(x))

#define oo LLONG_MAX

vector<lli> Generate(vector<int> vec) {
    vector<ll> vecSum;
    int __size = vec.size();

    for (int i = 0; i < (1 << __size); i++) {
        ll sum = 0;
        for (int j = 0; j < __size; j++) {
            if ((i >> j) & 1) 
                sum += vec[j];
            else   
                sum -= vec[j];
        }
        vecSum.push_back(sum);
    }
    sort(vecSum.begin(), vecSum.end());
    
    vector<lli> ret(1, lli(vecSum[0], 1));
    for (int i = 1; i < (int)vecSum.size(); i++) {  
        if (vecSum[i] != ret[ret.size() - 1].first)
            ret.push_back(lli(vecSum[i], 1));
        else    
            ret[ret.size() - 1].second++;
    }
    return ret;
}

void Minimize(ll& res, int& cnt, lli a, lli b) {
    ll temp = abs(a.first - b.first);
    if (temp < res) {
        res = temp;
        cnt = a.second * b.second;
        return;
    } 
    if (temp == res) 
        cnt += a.second * b.second;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n / 2), b(n - n / 2);
    for (int& x: a)
        cin >> x;
    for (int& x: b)
        cin >> x;
    
    vector<lli> prefSet(Generate(a));
    vector<lli> suffSet(Generate(b));

    ll res = +oo;
    int cnt = 0;
    int n1 = prefSet.size(), n2 = suffSet.size();
    for (int i = 0, j = 0; i < n1; i++) {
        for (; j < n2; j++) {
            if (suffSet[j].first > prefSet[i].first)
                break;
        }

        if (!j) {
            Minimize(res, cnt, prefSet[i], suffSet[j]);
            continue;
        }
        if (j == n2) {
            Minimize(res, cnt, prefSet[i], suffSet[j - 1]);
            break;
        }
        Minimize(res, cnt, prefSet[i], suffSet[j]);
        Minimize(res, cnt, prefSet[i], suffSet[j - 1]);
    }

    cout << res << " " << cnt / 2 << "\n";
}