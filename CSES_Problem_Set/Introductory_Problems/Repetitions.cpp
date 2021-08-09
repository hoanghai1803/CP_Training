#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	string dna;
	cin >> dna;
	
	char prev = dna[0];
	int res = 0;
	int _len = 1;
	for (unsigned i = 1; i < dna.length(); i++) {
		if (dna[i] == prev)
			_len++;
		else {
			res = max(res, _len);
			_len = 1;
			prev = dna[i];
		}
	}
	res = max(res, _len);
	cout << res;
}