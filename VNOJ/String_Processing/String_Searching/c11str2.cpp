// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    vector<int> pi = prefix_function(b + a);
    int len = min(pi[(b+a).size() - 1], (int)b.size());
    cout << a + b.substr(len) << "\n";
}