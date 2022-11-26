// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    // Generate hash code
    mt19937_64 rng(seed);

    auto get_rand = [&](int l, int r) { return rng() % (r - l + 1) + l; };

    int m, n;
    cin >> m >> n;
    for (int u = 1; u < m; u++) cout << u << " " << u + 1 << endl;
    int dia = m - 1;

    const int ITER = 222;
    for (int i = 0; i < ITER; i++) {
        int dist, len1, len2;
        int u = get_rand(1, n - 1);
        int v = get_rand(u + 1, n);

        cout << "distance " << u << " " << v << endl;
        cin >> dist;
        cout << "subtree " << u << " " << v << endl;
        cin >> len1;
        cout << "subtree " << v << " " << u << endl;
        cin >> len2;

        dia = max(dia, len1 + len2 - dist);
    }

    cout << "! " << dia << endl;
}