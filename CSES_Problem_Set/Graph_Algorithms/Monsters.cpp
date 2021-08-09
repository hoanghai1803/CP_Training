#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii;
 
#define oo INT_MAX
#define MAX_N 1003
 
int dx[] = {-1, 0, 0, 1};	
int dy[] = {0, 1, -1, 0};
int dmove[] = {'D', 'L', 'R', 'U'};
 
int n, m;
char maze[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int danger[MAX_N][MAX_N]; // the minimum steps that any monster can reach to a square
int steps[MAX_N][MAX_N]; // the minimum steps that human can reach to a square
int trace[MAX_N][MAX_N];
ii finish;
 
// Calculate the minimum steps that any monster can reach to each floor square
void calcMonsters() {
	queue<ii> Q;
	for (int u = 1; u <= n; u++) 
		for (int v = 1; v <= m; v++) { 
			danger[u][v] = +oo;	
			if (maze[u][v] == 'M') danger[u][v] = 0, Q.push(ii(u, v));
		}
	
	while (Q.size()) {
		int u = Q.front().first, v = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int _u = u + dx[i], _v = v + dy[i];
			if ((maze[_u][_v] == '.' || maze[_u][_v] == 'A') && !visited[_u][_v]) {
				visited[_u][_v] = true;
				danger[_u][_v] = danger[u][v] + 1;
				Q.push(ii(_u, _v));
			}
		}
	}	
}
 
bool findPath() {	
	memset(visited, false, sizeof(visited));
	queue<ii> Q;	
	for (int u = 1; u <= n; u++) 
		for (int v = 1; v <= m; v++) 
			if (maze[u][v] == 'A') Q.push(ii(u, v));
	
	while (Q.size()) {
		int u = Q.front().first, v = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int _u = u + dx[i], _v = v + dy[i];
			// If reach to border of labyrinth, return the solution
			if (!_u || _u > n || !_v || _v > m) {
				finish = ii(u, v);
				return true;
			}
 
			// Only consider the squares '.' and haven't visited.
			if (maze[_u][_v] != '.' || visited[_u][_v]) continue;
			visited[_u][_v] = true;
 
			// If any monsters can reach to this square before the human, 
			// do not consider it anymore.
			if (danger[_u][_v] <= steps[u][v] + 1) continue;
			steps[_u][_v] = steps[u][v] + 1;	
			trace[_u][_v] = 3 - i;
			Q.push(ii(_u, _v));
		}
	}
 
	return false;
}
 
int main() {
	scanf("%d%d", &n, &m);
	for (int u = 1; u <= n; u++) scanf("%s", maze[u] + 1);
	calcMonsters();
 
	if (!findPath()) {
		printf("NO");
		return 0;
	}
 
	vector<char> path;
	int u = finish.first, v = finish.second;
	printf("YES\n%d\n", steps[u][v]);
 
	while (maze[u][v] != 'A') {
		path.push_back(dmove[trace[u][v]]);
		int _u = u + dx[trace[u][v]], _v = v + dy[trace[u][v]];
		u = _u, v = _v;
	}
 
	reverse(path.begin(), path.end());
	for (char d: path) printf("%c", d);
}