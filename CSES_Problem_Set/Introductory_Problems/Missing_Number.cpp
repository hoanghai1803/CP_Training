// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
 
int n;
bool exist[N];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int num;
		cin >> num;
		exist[num] = true;
	}
 
	for (int num = 1; num <= n; num++) {
		if (!exist[num]) {
			cout << num << endl;
			break;
		}
	}
}