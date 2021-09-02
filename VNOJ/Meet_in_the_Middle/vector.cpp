// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
#define X first
#define Y second

int U, V;
map<ii, int> cnt;
int res = 0;

void BruteForce(int id, vector<ii> vec) {
    int __size = vec.size();

    for (int i = 0; i < (1 << __size); i++) {
        int u = 0, v = 0;
        for (int j = 0; j < __size; j++) 
            if ((i >> j) & 1) 
                u += vec[j].X, v += vec[j].Y;
        if (id == 1)
            cnt[ii(u, v)]++;
        else    
            res += cnt[ii(U - u, V - v)];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ii> a(n / 2), b(n - n / 2);
    for (ii& v: a) cin >> v.X >> v.Y;
    for (ii& v: b) cin >> v.X >> v.Y;
    cin >> U >> V;
    
    BruteForce(1, a);
    BruteForce(2, b);
    cout << res << "\n";
}