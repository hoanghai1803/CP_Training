// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	
	while (t--) {
		long long y, x;
		cin >> y >> x;
		long long z = max(y, x) - 1;
		long long start = z * z;
		if (z & 1) 
			cout << start + y + (y - x) * (x < y) << "\n";
		else 
			cout << start + x + (x - y) * (x > y) << "\n";
	}
}