#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 200005
 
int n;
pair<int, int> customers[MAX_N];
priority_queue<int, vector<int>, greater<int> > leavingTimes;
int currentCustomers, res;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> customers[i].first >> customers[i].second;
	sort(customers, customers + n);
 
	for (int i = 0; i < n; i++) {
		currentCustomers++;
		leavingTimes.push(customers[i].second);
		while (leavingTimes.top() < customers[i].first) 
			currentCustomers--, leavingTimes.pop();
		res = max(currentCustomers, res);
	}
 
	cout << res;
}