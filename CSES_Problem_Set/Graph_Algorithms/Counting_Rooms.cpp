// Author: __BruteForce__
#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii;
 
#define MAX_N 1003

int n, m;
char squares[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int rooms;
 
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
 
void bfs(int u, int v) {
	visited[u][v] = true;
	queue<ii> Q;
	Q.push(ii(u, v));
 
	while (Q.size()) {
		int u = Q.front().first, v = Q.front().second;
		Q.pop();
 
		for (int i = 0; i < 4; i++) {
			int _u = u + dx[i], _v = v + dy[i];
			if (squares[_u][_v] == '.' && !visited[_u][_v]) 
				visited[_u][_v] = true, Q.push(ii(_u, _v));
		}	 
	}
}
 
int main() {
	scanf("%d%d", &n, &m);
	for (int u = 1; u <= n; u++) scanf("%s", squares[u] + 1);
	
	for (int u = 1; u <= n; u++) 
		for (int v = 1; v <= m; v++) 
			if (squares[u][v] == '.' && !visited[u][v]) {
				rooms++;
				bfs(u, v);
			}
 
	printf("%d", rooms);		
}