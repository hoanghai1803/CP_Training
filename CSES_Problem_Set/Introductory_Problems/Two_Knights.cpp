// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
#define sqr(a) (a) * (a)
 
const int N = 1e4 + 4;
 
int n;
long long res[N];
 
int main() {
	res[2] = 6;
	res[3] = 28;
	res[4] = 96;
 
	cin >> n;
 
	for (long long i = 1; i <= n; i++) {
		if (i <= 4) {
			cout << res[i] << "\n";
			continue;
		}
 
		long long border = 2 * i - 1;
		res[i] = res[i - 1];
		res[i] += sqr(i - 3) * border;
		res[i] += 2 * (border - 1) + (border - 4) + (2 * (i - 2) - 4) * (border - 2);
		res[i] += 4 * (border - 1) + 2 * (border - 3) + (2 * (i - 1) - 7) * (border - 2);
		res[i] += border * (border - 1) / 2 - 2;
		
		cout << res[i] << "\n";
	}
}