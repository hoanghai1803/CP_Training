#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000006

long long prefCount[MAX_N], prefSum[MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    prefCount[1] = prefSum[1] = 1;
    for (int i = 2; i < MAX_N; i++)
        prefCount[i] = 2, prefSum[i] = i + 1;
    
    for (int i = 2; i < MAX_N; i++) {
        for (int j = i + i; j < MAX_N; j += i)
            prefCount[j]++, prefSum[j] += i;
        prefCount[i] += prefCount[i - 1];
        prefSum[i] += prefSum[i - 1];
    }

    int t, x, y;
    for (cin >> t; t--;) {
        cin >> x >> y;
        cout << prefCount[y] - prefCount[x - 1] << " " << prefSum[y] - prefSum[x - 1] << "\n";
    }
}