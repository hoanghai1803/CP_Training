// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

void Try(vector<int> vec, int i, vector<ii>& returnSet, int sum1 = 0, int sum2 = 0) {
    if (i == (int)vec.size()) {
        returnSet.push_back(ii(sum1 - sum2, sum1 + sum2));
        return;
    }

    Try(vec, i + 1, returnSet, sum1, sum2);
    Try(vec, i + 1, returnSet, sum1 + vec[i], sum2);
    Try(vec, i + 1, returnSet, sum1, sum2 + vec[i]);
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

    vector<ii> prefSet, suffSet;
    Try(a, 0, prefSet);
    int n1 = prefSet.size();
    sort(prefSet.begin(), prefSet.end());

    Try(b, 0, suffSet);
    int n2 = suffSet.size();
    sort(suffSet.begin(), suffSet.end());

    int res = 0;
    for (int i = 0, j = n2 - 1; i < n1; i++) {
        while (j && prefSet[i].first + suffSet[j].first > 0)
            j--;
        if (prefSet[i].first + suffSet[j].first == 0)
            res = max(res, (prefSet[i].second + suffSet[j].second) / 2);
    }
    cout << res << "\n";
}