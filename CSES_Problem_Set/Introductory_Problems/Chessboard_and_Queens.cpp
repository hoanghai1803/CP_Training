// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10

bool Free[MAX_N][MAX_N];
bool col[MAX_N], dia_1[MAX_N * 2], dia_2[MAX_N * 2];
int res = 0;

int Id(int x) {
    return x + MAX_N;
}

void Try(int r) {
    if (r > 8) {
        res++;
        return;
    }

    for (int c = 1; c <= 8; c++) {
        if (Free[r][c] && !col[c] && !dia_1[r + c] && !dia_2[Id(r - c)]) {
            col[c] = dia_1[r + c] = dia_2[Id(r - c)] = true;
            Try(r + 1);
            col[c] = dia_1[r + c] = dia_2[Id(r - c)] = false;
        }
    }
}

int main() {
    char square;
    for (int r = 1; r <= 8; r++) 
        for (int c = 1; c <= 8; c++) {
            cin >> square;
            Free[r][c] = square == '.';
        }
    Try(1);
    cout << res << "\n";
}