// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 55

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

char s[MAX_N];
bool Free[MAX_N][MAX_N];
map<char, int> mapDir;
int res;

void FindPath(int id, int u, int v) {
    if (id == 49) {
        res += (u == 7 && v == 1);
        return;
    }

    // Optimization 
    if (u == 7 && v == 1)
        return;

    bool chk[8];
    for (int i = 0; i < 8; i++)
        chk[i] = Free[u + dx[i]][v + dy[i]];

	if (chk[0] && chk[1]) {
		if (!chk[2] && !chk[3])
			return;
		if (!chk[2] && (!chk[5] || !chk[7]))
			return;
		if (!chk[3] && (!chk[4] || !chk[6]))
			return;
	}

	if (chk[2] && chk[3]) {
		if (!chk[0] && !chk[1])
			return;
		if (!chk[0] && (!chk[6] || !chk[7]))
			return;
		if (!chk[1] && (!chk[4] || !chk[5]))
			return;
	}

    // Satisfy the condition
    if (s[id] != '?') {
        int uu = u + dx[mapDir[s[id]]];
        int vv = v + dy[mapDir[s[id]]];
        if (!Free[uu][vv])
            return;
            
        Free[uu][vv] = false;
        FindPath(id + 1, uu, vv);
        Free[uu][vv] = true;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int uu = u + dx[i], vv = v + dy[i];
        if (!Free[uu][vv])
            continue;
            
        Free[uu][vv] = false;
        FindPath(id + 1, uu, vv);
        Free[uu][vv] = true;
    }
}

int main() {
    scanf("%s", s + 1);
    mapDir['D'] = 0, mapDir['U'] = 1, mapDir['L'] = 2, mapDir['R'] = 3;

    for (int u = 1; u < 8; u++)
        for (int v = 1; v < 8; v++)
            Free[u][v] = true;
    Free[1][1] = false;

    FindPath(1, 1, 1);
    cout << res << "\n";
}
