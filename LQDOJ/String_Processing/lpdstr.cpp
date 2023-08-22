// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MOD (int)(1e9+7)
#define MAX_N 333

int lpes[MAX_N][3]; // longest prefix equals to suffix
int dp[MAX_N][MAX_N][MAX_N][3];

string s;
string pref_str[MAX_N];

void inc(int& num, int adder) {
	num = (num + adder) % MOD;
}

int prefix_equals_suffix(string s) {
	for (int len = s.size(); len; len--) {
		if(pref_str[len] == s) return len;
		s.erase(0, 1);
	}
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

	int n, m, slen;
	cin >> n >> m >> slen;
	cin >> s;

	pref_str[0] = "";
	for(int len = 1; len <= slen; len++) {
        pref_str[len] = s.substr(0, len);
	}

	string t = "";
	for(int pref = 0; pref <= slen; pref++) {
		if(pref) t += s[pref-1];
		lpes[pref][0] = prefix_equals_suffix(t + 'L');
		lpes[pref][1] = prefix_equals_suffix(t + 'P');
		lpes[pref][2] = prefix_equals_suffix(t + 'D');
	}

	dp[0][0][0][0] = 1;
	for (int len = 0; len < n; len++)
		for (int num_l = 0; num_l <= len; num_l++)
			for (int pref = 0; pref <= slen; pref++)
				for (int contains = 0; contains < 2; contains++) {
					if(!dp[len][num_l][pref][contains]) continue;
					// Choose L
					int new_pref = lpes[pref][0];
					int new_contains = contains | (new_pref == slen);
					inc(dp[len+1][num_l+1][new_pref][new_contains], dp[len][num_l][pref][contains]);

					// Choose P
					new_pref = lpes[pref][1];
					new_contains = contains | (new_pref == slen);
					inc(dp[len+1][num_l][new_pref][new_contains], dp[len][num_l][pref][contains]);

					// Choose D
					new_pref = lpes[pref][2];
					new_contains = contains | (new_pref == slen);
					inc(dp[len+1][num_l][new_pref][new_contains], dp[len][num_l][pref][contains]);
				}

	int ans = 0;
	for(int num_l = m; num_l <= n; num_l++)
		for(int i = 0; i <= slen; i++)
			inc(ans, dp[n][num_l][i][0]);
	cout << ans << "\n";
}