// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 200005
 
int n, id, start = 1;
int k[MAX_N];
map<int, int> position;
int res = 0;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		if (position[k[i]]) {
			int new_start = position[k[i]] + 1;
			for (int j = start; j <= position[k[i]]; j++) position.erase(k[j]);
			start = new_start;
		}
		position[k[i]] = i;
		res = max(res, i - start + 1);
	}
	cout << res;
}