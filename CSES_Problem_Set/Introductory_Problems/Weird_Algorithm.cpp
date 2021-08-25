// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	long long n;
	cin >> n;
	cout << n << " "; 
	while (n != 1) { 
		if (n & 1) {
			n = n * 3 + 1;
		} else {
			n /= 2;
		}	
		cout << n << " ";
	} 
	cout << endl;
}