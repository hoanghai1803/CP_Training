#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, a;
    queue<int> qu;

    cin >> n;
    vector<int> dist(n, 0);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (!a) {
            qu.push(i);
            visited[i] = true;
        }
    }

    while (qu.size()) {
        int pos = qu.front();
        qu.pop();
        if (pos + 1 < n && !visited[pos + 1]) {
            visited[pos + 1] = true;
            dist[pos + 1] = dist[pos] + 1;
            qu.push(pos + 1);
        }
        if (pos - 1 >= 0 && !visited[pos - 1]) {
            visited[pos - 1] = true;
            dist[pos - 1] = dist[pos] + 1;
            qu.push(pos - 1);
        }
    }

    for (auto d: dist) 
        cout << d << " ";
}