#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii;
 
const int MAX_N = 1e3 + 3;
#define MAX_N 1003
 
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
int dmove[] = {'D', 'L', 'R', 'U'};
 
int n, m;
char maze[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int trace[MAX_N][MAX_N];
ii start, finish;
 
bool bfs(ii start) {
	int u = start.first, v = start.second;
	visited[u][v] = true;
	queue<ii> Q;
	Q.push(ii(u, v));
 
	while (Q.size()) {
		int u = Q.front().first, v = Q.front().second;
		Q.pop();
 
		for (int i = 0; i < 4; i++) {
			int _u = u + dx[i], _v = v + dy[i];
 
			if (maze[_u][_v] == 'B') {
				trace[_u][_v] = 3 - i;
				finish = ii(_u, _v);
				return true;
			}
 
			if (maze[_u][_v] == '.' && !visited[_u][_v]) {
				trace[_u][_v] = 3 - i;
 				visited[_u][_v] = true; 
				Q.push(ii(_u, _v));
			}
		}
	}
	
	return false;
}
 
int main() {
	scanf("%d%d", &n, &m);
	for (int u = 1; u <= n; u++) scanf("%s", maze[u] + 1);
 
	for (int u = 1; u <= n; u++) 
		for (int v = 1; v <= m; v++) 
			if (maze[u][v] == 'A') start = ii(u, v);
 
	if (!bfs(start)) {
		printf("NO");
		return 0; 
	}
 
	printf("YES\n");
	
	vector<char> path;
	int u = finish.first, v = finish.second;
	while (1) {
		path.push_back(dmove[trace[u][v]]);
		int _u = u + dx[trace[u][v]], _v = v + dy[trace[u][v]];
		if (ii(u = _u, v = _v) == start) break;
	}
 
	printf("%ld\n", path.size());	
	reverse(path.begin(), path.end());
	for (char d: path) printf("%c", d);	
}