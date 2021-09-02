#include <bits/stdc++.h>
 
using namespace std;

 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    int n;
    cin >> n;
 
    vector<int> vec(n);
    long long sum = 0, sumSuffix = 0;
    map<long long, long long> prefix, suffix;
    for (int& ele: vec) {
        cin >> ele;
        sum += ele, prefix[ele]++;
    }
 
    if (sum & 1) {
        cout << "NO\n";
        return 0;
    }
 
    sum /= 2;
    for (int ele: vec) {
        sumSuffix += ele;
        prefix[ele]--, suffix[ele]++;
        if ((sum > sumSuffix && prefix[sum - sumSuffix]) || (sum < sumSuffix && suffix[sumSuffix - sum])) {
            cout << "YES\n";
            return 0;   
        }
    }
    cout << "NO\n";
}