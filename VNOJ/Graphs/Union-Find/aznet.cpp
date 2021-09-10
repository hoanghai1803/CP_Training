// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, v;;
    int c;
};  

void reset(vector<int>& par) {
    for (int u = 1; u <= par.size() - 1; u++) par[u] = u;
}

int findRoot(int u, vector<int>& par) {
    if (par[u] == u)
        return u;
    return par[u] = findRoot(par[u], par);
}

bool Union(int u, int v, vector<int>& par) {
    if ((u = findRoot(u, par)) == (v = findRoot(v, par))) return 0;
    par[u] = v;
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int T;
    for (cin >> T; T--;) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n, 0), b(n, 0);
        for (int i = 1; i < n; i++) cin >> a[i];
        for (int i = 1; i < n; i++) cin >> b[i];

        vector<edge> e(m);
        for (edge& _e: e) cin >> _e.u >> _e.v >> _e.c; 

        vector<int> par(n + 1);

        reset(par);
        int maxA = 0;
        for (edge& _e: e) 
            if (_e.c == 1) maxA += Union(_e.u, _e.v, par);
    
        reset(par);
        int maxB = 0;
        for (edge& _e: e)
            if (_e.c == 2) maxB += Union(_e.u, _e.v, par);

        int x, minCost = INT_MAX;
        for (int i = max(0, n - 1 - maxB); i <= min(maxA, n - 1); i++)
            if (a[i] + b[n - 1 - i] < minCost) { 
                x = i;
                minCost = a[x] + b[n - 1 - x];
            }    

        vector<bool> taken(m, 0);
        int cnt = 0;
        for (int i = 0; i < e.size(); i++)
            if (e[i].c == 1) 
                cnt += (taken[i] = Union(e[i].u, e[i].v, par));

        reset(par);
        for (int i = 0; i < e.size() && cnt < x; i++)
            if (e[i].c == 1) {
                bool takenEdge = Union(e[i].u, e[i].v, par);
                cnt += (takenEdge && !taken[i]);
                taken[i] = takenEdge;
            }

        for (int i = 0; i < e.size(); i++)
            if (e[i].c == 2) 
                taken[i] = Union(e[i].u, e[i].v, par);

        // Print out result
        for (int i = 0; i < e.size(); i++)
            if (taken[i]) cout << i + 1 << " "; // i + 1 because vector e and taken index from 0
        cout << "\n";       
    }
}