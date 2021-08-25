// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
const long long oo = LLONG_MAX;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	long long sum = 0, min_sum = 0, res = -oo;
	cin >> n;
	while (n--) {
		int val;
		cin >> val;
		sum += val;
		res = max(res, sum - min_sum);
		min_sum = min(min_sum, sum);
	}
	cout << res;
}