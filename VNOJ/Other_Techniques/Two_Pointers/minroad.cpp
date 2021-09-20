// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define dist first
#define type second

#define oo INT_MAX
#define MAX_N 300005

int n, a, b;
ii tree[MAX_N];
int tung[MAX_N], truc[MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) 
        cin >> tree[i].dist >> tree[i].type;
    sort(tree + 1, tree + 1 + n);
    
    for (int i = 1; i <= n; i++) {
        tung[i] = tung[i - 1] + (tree[i].type == 1);
        truc[i] = truc[i - 1] + (tree[i].type == 2);
    }

    int res = +oo;
    for (int L = 1, R = 2; ; L++) {
        while (R <= n && (tung[R] - tung[L - 1] < a || truc[R] - truc[L - 1] < b))
            R++;
        if (R > n)
            break;
        res = min(res, tree[R].dist - tree[L].dist);
    }

    if (res == +oo)
        cout << "-1\n";
    else 
        cout << res << "\n";
}