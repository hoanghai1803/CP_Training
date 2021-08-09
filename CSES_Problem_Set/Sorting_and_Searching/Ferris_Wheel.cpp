#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5 + 5;
 
int n, x;
int p[MAX_N];
int gondolas;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x;
	for (int i = 0; i < n; i++) 
		cin >> p[i];
	sort(p, p + n);
 
	for (int i = 0, j = n - 1; i <= j; i++) {
		for (; p[i] + p[j] > x && i < j; j--) gondolas++;
		gondolas++;
		if (i == j) break;
		j--;
	}
	cout << gondolas;
}