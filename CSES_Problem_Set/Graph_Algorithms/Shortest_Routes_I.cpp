#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
 
const long long oo = 1e15;
#define MAX_N 100005
 
int n, m;
long long F[MAX_N];
vector<ii> flights[MAX_N];
priority_queue<lli, vector<lli>, greater<lli> > Heap;
 
void Dijkstra() {
	long long Fu;
	int  u, v;
	Heap.push(lli(F[1], 1));
	while (Heap.size()) {
		Fu = Heap.top().first, u = Heap.top().second;
		Heap.pop();
		if (Fu != F[u]) continue;
		for (ii flight: flights[u]) 
			if (F[v = flight.first] > F[u] + flight.second) {
				F[v] = F[u] + flight.second;
				Heap.push(lli(F[v], v));
			} 
	}
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	while (m--) {
		int u, v, l;
		cin >> u >> v >> l;
		flights[u].push_back(ii(v, l));
	}
 
	for (int u = 2; u <= n; u++) F[u] = +oo;
	Dijkstra();
 
	for (int u = 1; u <= n; u++) cout << F[u] << " ";
}