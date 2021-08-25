// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
long long power(int n) {
	if (n == 1) return 2;
	int half = n / 2;
	if (n & 1) return power(half) * power(half) * 2 % MOD;
	return power(half) * power(half) % MOD;
}
 
int main() {
	int n;
	cin >> n;
	cout << power(n);
}