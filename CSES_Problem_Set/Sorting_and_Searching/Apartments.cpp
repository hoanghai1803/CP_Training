// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5 + 5;
 
int n, m, k;
int a[MAX_N], b[MAX_N];
int res;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	
	sort(a, a + n);
	sort(b, b + m);
 
	for (int i = 0, j = 0; i < n && j < m; i++) {
		for (; a[i] - k > b[j] && j < m; j++) {}
		if (j == m) break;
		if (a[i] + k < b[j]) continue;
		res++, j++;
	}
	
	cout << res;
}
