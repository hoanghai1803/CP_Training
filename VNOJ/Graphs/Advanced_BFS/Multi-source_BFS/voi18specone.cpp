// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

int n, k, s, m;
int cnt = 0;
map<string, int> id;
string stu[MAX_N];
bool spec[MAX_N];
int text[MAX_N];
vector<int> adj[MAX_N];
vector<string> res;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k >> s >> m;
    while (s--) {
        string name;
        cin >> name;
        if (!id[name]) {
            id[name] = ++cnt;
            stu[cnt] = name;
            res.push_back(name);
        }
        spec[id[name]] = true;
    }

    while (m--) {
        string s1, s2;
        cin >> s1 >> s2;
        if (!id[s1]) {
            id[s1] = ++cnt;
            stu[cnt] = s1;
        }
        if (!id[s2]) {
            id[s2] = ++cnt;
            stu[cnt] = s2;
        }
        adj[id[s1]].push_back(id[s2]);
        adj[id[s2]].push_back(id[s1]);
    }

    for (int u = 1; u <= n; u++) {
        sort(adj[u].begin(), adj[u].end());
        adj[u].resize(unique(adj[u].begin(), adj[u].end()) - adj[u].begin());
    }

    // DP
    queue<int> Q;
    for (int u = 1; u <= n; u++)
        if (spec[u]) Q.push(u);
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (int v: adj[u]) {
            if (spec[v]) continue;
            if (++text[v] >= k) {
                spec[v] = true;
                res.push_back(stu[v]);
                Q.push(v);
            }
        }
    }

    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (auto name: res) cout << name << " ";
}