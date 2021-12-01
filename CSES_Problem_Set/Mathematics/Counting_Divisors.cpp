// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000006

int gpd[MAX_N]; // greatest prime divisor

void sieve() {
    for (int i = 1; i < MAX_N; i++)
        gpd[i] = i;
    
    for (int i = 2; i * i < MAX_N; i++)
        if (gpd[i] == i)
            for (int j = 2 * i; j < MAX_N; j += i) 
                gpd[j] = i;
}

int numberOfDivisors(int num) {
    int ret = 1, pre = -1, cnt = 0;
    while (num != 1) 
        if (gpd[num] == pre) {
            cnt++; 
            num /= gpd[num];
        } else {
            ret *= (cnt + 1);
            cnt = 1;
            pre = gpd[num], num /= gpd[num];
        }
    return ret * (cnt + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    sieve();
    int n, x;
    for (cin >> n; n--;) {
        cin >> x;
        cout << numberOfDivisors(x) << "\n";
    }
}