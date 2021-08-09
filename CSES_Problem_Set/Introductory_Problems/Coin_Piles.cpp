#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if ((a + b) % 3 || (a + b) / 3 > min(a, b)) cout << "NO\n";
		else cout << "YES\n";
	}
}