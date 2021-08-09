#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005

int n;
int num, res;
bool appeared[MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    while (n--) {
        cin >> num;
        res += !appeared[num - 1];
        appeared[num] = true;
    }
    cout << res << "\n";
}