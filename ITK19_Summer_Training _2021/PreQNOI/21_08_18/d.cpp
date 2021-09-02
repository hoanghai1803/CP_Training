#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1003

int n, k;
string s;
bool mark[MAX_N][MAX_N][3][2];
vector<char> res;

struct State {
    int n, k, i, j;
} trace[MAX_N][MAX_N][3][2];

void Update(int n, int k, int i, int j, int _n, int _k, int _i, int _j) {
    if (mark[_n][_k][_i][_j]) {
        mark[n][k][i][j] = true;
        trace[n][k][i][j] = {_n, _k, _i, _j};
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    n--;
    cin >> s;
    if (!n) {
        if (k == 1 && s[0] != 'D')
            cout << (s[0] != '?' ? s[0] : 'W');
        else    
            cout << "NO\n";
        return 0;
    }

    if (s[0] == 'L' && k > 1)
        mark[0][1][0][0] = true;
    if (s[0] == 'W' && k > 1)
        mark[0][1][2][1] = true;
    if (s[0] == 'D')
        mark[0][0][1][0] = mark[0][0][1][1] = true;
    if (s[0] == '?') {
        if (k > 1) {
            mark[0][1][0][0] = true;
            mark[0][1][2][1] = true;
        }
        mark[0][0][1][0] = mark[0][0][1][1] = true;
    }

    for (int i = 1; i < n; i++) { 
        if (s[i] == 'L' || s[i] == '?') {
            for (int t = 0; t <= 2; t++) {
                Update(i, 0, 0, 0, i - 1, 1, t, 1);
                Update(i, 0, 0, 1, i - 1, 1, t, 1);
            }
            for (int j = 1; j < k; j++) 
                for (int t = 0; t <= 2; t++) {
                    Update(i, j, 0, 0, i - 1, j - 1, t, 0);
                    Update(i, j, 0, 1, i - 1, j + 1, t, 1);
                }
        }
        
        if (s[i] == 'D' || s[i] == '?') 
            for (int j = 0; j < k; j++) 
                for (int t = 0; t <= 2; t++) {
                    Update(i, j, 1, 0, i - 1, j, t, 0);
                    Update(i, j, 1, 1, i - 1, j, t, 1);
                }

        if (s[i] == 'W' || s[i] == '?') {
            for (int t = 0; t <= 2; t++) {
                Update(i, 0, 2, 0, i - 1, 1, t, 0);
                Update(i, 0, 2, 1, i - 1, 1, t, 0);
            }
            for (int j = 1; j < k; j++) 
                for (int t = 0; t <= 2; t++) {
                    Update(i, j, 2, 1, i - 1, j - 1, t, 1);
                    Update(i, j, 2, 0, i - 1, j + 1, t, 0);
                }
        }
    }

    if (s[n] == 'D') {
        cout << "NO\n";
        return 0;
    }

    int i, j;
    bool chk = false;

    if (s[n] == 'L' || s[n] == '?') 
        for (int t = 0; t <= 2; t++)
            if (mark[n - 1][k - 1][t][0])
                chk = true, i = t, j = 0;
    if (chk) 
        res.push_back('L');

    if (!chk) {
        if (s[n] == 'W' || s[n] == '?') 
            for (int t = 0; t <= 2; t++)
                if (mark[n - 1][k - 1][t][1])
                    chk = true, i = t, j = 1;

        if (!chk) {
            cout << "NO\n";
            return 0;
        }

        res.push_back('W');
    }

    n--, k--;

    while (true) {
        if (!i)
            res.push_back('L');
        if (i == 1)
            res.push_back('D');
        if (i == 2)
            res.push_back('W');
        
        if (!n) 
            break;
        
        int _n = trace[n][k][i][j].n;
        int _k = trace[n][k][i][j].k;
        int _i = trace[n][k][i][j].i;
        int _j = trace[n][k][i][j].j;
        n = _n, k = _k, i = _i, j = _j;
    }

    for (int i = res.size() - 1; i >= 0; i--) 
        cout << res[i];
    cout << "\n";
}