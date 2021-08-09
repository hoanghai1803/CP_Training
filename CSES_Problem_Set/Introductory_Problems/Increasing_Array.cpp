#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	long long res = 0;
	long long prev = 0, num;
	for (unsigned i = 0; i < n; i++) {
		cin >> num;
		if (num < prev) {
			res += prev - num;
		} else {
			prev = num;
		}
	}
	cout << res << "\n";
}