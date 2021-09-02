#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x, y, l, r;
    cin >> x >> y >> l >> r;

    long long powX = 1, powY = 1;
    vector<long long> vecX, vecY, vecSum;
    while (1) {
        vecX.push_back(powX);
        if (r / x < powX)
            break;
        powX *= x;
    }
    while (1) {
        vecY.push_back(powY);
        if (r / y < powY)
            break;
        powY *= y;
    }

    for (auto _x: vecX) 
        for (auto _y: vecY) 
            vecSum.push_back(_x + _y);
    
    sort(vecSum.begin(), vecSum.end());
    auto it = vecSum.begin();
    while (*it < l) 
        it++;

    if (*it >= r) {
        cout << (r - l + (*it > r));
        return 0;
    }

    long long res = *it - l;
    it++;
    for (; it < vecSum.end() && *it < r; it++) 
        res = max(res, *it - *(it - 1) - 1);

    cout << max(res, r - *(it - 1) - (it != vecSum.end() && r == *it)) << "\n";
}