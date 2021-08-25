// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 200005
 
int n;
int p[MAX_N];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> p[i];
	sort(p, p + n);
 
	int median = n / 2;
	long long res = 0;
	for (int i = 0; i < n; i++) 
		res += abs(p[median] - p[i]);
	cout << res;
}