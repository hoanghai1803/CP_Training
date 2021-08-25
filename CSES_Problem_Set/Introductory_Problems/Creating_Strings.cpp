// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    int a = 1, b = 1, cnt = 1;
    for (int i = 1; i < s.length(); i++) {
        a *= i + 1;
        if (s[i] == s[i - 1])
            b *= ++cnt;
        else    
            cnt = 1;
    }

    cout << a / b << "\n" << s << "\n";
    while (next_permutation(s.begin(), s.end())) 
        cout << s << "\n";
}