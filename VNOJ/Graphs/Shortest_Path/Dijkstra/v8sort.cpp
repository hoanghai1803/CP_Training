// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int, vector<int>> State;

int c[11][11];
vector<int> arr;
map<vector<int>, int> cost;

bool isTarget(vector<int> arr) {
    for (int i = 0; i < (int)arr.size() - 1; i++)
        if (arr[i] > arr[i + 1]) return false;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // Init
    string inp;
    getline(cin, inp);
    stringstream ss(inp);
    int val;
    while (ss >> val) arr.push_back(val);
    int n = arr.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];

    // Dijkstra
    priority_queue<State, vector<State>, greater<State>> Heap;
    cost[arr] = 0;
    Heap.push({0, arr});
    while (Heap.size()) {
        int f = Heap.top().first;
        vector<int> stt = Heap.top().second;
        Heap.pop();
        if (f != cost[stt]) continue;
        if (isTarget(stt)) {
            cout << f << "\n";
            break;
        }

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                swap(stt[i], stt[j]);
                if (cost.find(stt) == cost.end() || cost[stt] > f + c[i][j]) {
                    cost[stt] = f + c[i][j];
                    Heap.push({cost[stt], stt});
                }
                swap(stt[i], stt[j]);
            }
    }
}