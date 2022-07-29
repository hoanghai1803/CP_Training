// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int64, int> pli;

#define MAX_VAL 100005

int a, b, c;
int64 d[MAX_VAL], h;
priority_queue<pli, vector<pli>, greater<pli>> Heap;

void update(int u, int64 val) {
    if (d[u] >  val) {
        d[u] = val;
        Heap.push({d[u], u});
    }
}
    
int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> h >> a >> b >> c;

    // Dijkstra
    memset(d, 0x3f, sizeof(d));
    d[0] = 0;
    Heap.push({0, 0});
    while(Heap.size()) {
        int64 du = Heap.top().first;
        int u = Heap.top().second;
        Heap.pop();
        update((u + b) % a, du + b);
        update((u + c) % a, du + c);
    }

    int64 ans = 0;
    for (int u = 0; u < a; u++) 
        if (d[u] < h) ans += (h - d[u] - 1) / a + 1;
    cout << ans << "\n";
}