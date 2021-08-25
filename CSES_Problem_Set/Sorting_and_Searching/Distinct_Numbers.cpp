// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
int n, x;
int cnt;
map<int, bool> exist;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> x;
		if (!exist[x]) exist[x] = true, cnt++;
	}
	cout << cnt;
}