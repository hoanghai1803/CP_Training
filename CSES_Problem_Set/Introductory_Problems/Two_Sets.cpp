// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
 
	long long _sum = 1LL * n * (n + 1) / 2;
 
	if (_sum & 1) {
		cout << "NO";
		return 0;
	} 
 
	cout << "YES";
	_sum /= 2;
	vector<int> set1, set2;
	
	while (n) {
		if (_sum - n >= 0) set1.push_back(n), _sum -= n;
		else set2.push_back(n);
		n--;
	}
 
	cout << "\n" << set1.size() << "\n";
	for (int num: set1) cout << num << " ";
	cout << "\n" << set2.size() << "\n";
	for (int num: set2) cout << num << " ";
}