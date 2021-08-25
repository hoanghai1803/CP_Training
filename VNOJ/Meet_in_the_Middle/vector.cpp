// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

#define MAX_N 33

int n;
ii vec[MAX_N];
int U, V;
bool Choose[MAX_N];
map<ii, int> cnt;
int res;

void BruteForce(int id, int i, int f) {
    if (i > f) {
        int u = 0, v = 0;
        for (int i = 1; i <= f; i++) 
            if (Choose[i])
                u += vec[i].X, v += vec[i].Y;
        if (id == 1) 
            cnt[ii(u, v)]++;
        else 
            res += cnt[ii(U - u, V - v)];
        return;
    }

    BruteForce(id, i + 1, f);
    Choose[i] = true;
    BruteForce(id, i + 1, f);
    Choose[i] = false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> vec[i].X >> vec[i].Y;
    cin >> U >> V;
    
    BruteForce(1, 1, n / 2);
    BruteForce(2, n / 2 + 1, n);
    cout << res << "\n";
}