// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 2e5 + 5;
 
int n, m;
map<int, int> tickets; 
 
int findTicket(int money) {
	map<int, int>::iterator ticket = tickets.lower_bound(money);
	if (ticket != tickets.end()) {
		int price = ticket->first;
		if (!--ticket->second) tickets.erase(ticket);
		return -price;
	}
	return -1;
}
 
int main() {
	ios_base::sync_with_stdio(false); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int price;
		cin >> price;
		price *= -1;
		tickets[price] = tickets[price] ? tickets[price] + 1 : 1;
	}
 
	while(m--) {
		int money;
		cin >> money;
		money *= -1;
		cout << findTicket(money) << "\n";
	}
}