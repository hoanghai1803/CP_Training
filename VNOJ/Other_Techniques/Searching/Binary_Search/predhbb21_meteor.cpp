// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, R;
    cin >> n >> R;
    
    vector<double> start, finish;
    for (int i = 0; i < n; i++) {
        ll x, y, z, vx, vy, vz;
        cin >> x >> y >> z >> vx >> vy >> vz;

        ll A = vx * vx + vy * vy + vz* vz;
        ll B = 2 * (x * vx + y * vy + z * vz);
        ll C = x * x + y * y + z * z - 1LL * R * R;
    
        // Solve the in-equation: At^2 + Bt + C <= 0
        ll D = B * B - 4 * A * C;
        if (D < 0) continue;

        double t1 = max((- sqrt(D) - B) / (2 * A), 0.0);
        double t2 = (sqrt(D) - B) / (2 * A);
        if (t2 < 0) continue;    

        start.push_back(t1), finish.push_back(t2);
    }

    sort(start.begin(), start.end());
    sort(finish.begin(), finish.end());
    int nDanger = start.size();

    int m;
    cin >> m;

    while (m--) {
        double t;
        cin >> t;

        int res = nDanger;
        res -= start.end() - upper_bound(start.begin(), start.end(), t);
        res -= lower_bound(finish.begin(), finish.end(), t) - finish.begin();
        cout << res << "\n";
    }
}