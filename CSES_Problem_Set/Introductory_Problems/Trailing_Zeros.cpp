// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 5; n / i >= 1; i *= 5) ans += n / i;
	cout << ans;
}