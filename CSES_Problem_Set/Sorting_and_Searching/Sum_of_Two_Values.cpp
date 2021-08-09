#include <bits/stdc++.h>
 
using namespace std;
 
int n, sum, a;
map<int, int> position;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> sum;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (position[sum - a]) {
			cout << i << " " << position[sum - a];
			return 0;
		}
		position[a] = i;
	}
	cout << "IMPOSSIBLE";
}