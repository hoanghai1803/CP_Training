#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1e6 + 6;
const int MAX_CH = 1e2 + 2;
 
char str[MAX_N];
int cnt[MAX_CH];
int odd, middleCharacter;
 
int main() {
	scanf("%s", str);
	for (char ch: str) cnt[ch]++;
	for (int ch = 'A'; ch <= 'Z'; ch++) 
		if (cnt[ch] & 1) odd++;
 
	if (odd > 1) {
		printf("NO SOLUTION");
		return 0;
	}
 
	for (int ch = 'A'; ch <= 'Z'; ch++) {
		if (cnt[ch] & 1) middleCharacter = ch;
		for (int i = 0; i < cnt[ch] / 2; i++) printf("%c", ch);
	}
 
	if (middleCharacter) printf("%c", middleCharacter);
 
	for (int ch = 'Z'; ch >= 'A'; ch--) 
		for (int i = 0; i < cnt[ch] / 2; i++) printf("%c", ch);
}