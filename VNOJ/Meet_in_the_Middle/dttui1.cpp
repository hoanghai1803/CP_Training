// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define W first
#define V second

vector<ii> Generate(vector<ii> vec, int M) {
    vector<ii> ret;
    int __size = vec.size();

    for (int i = 0; i < (1 << __size); i++) {
        int w = 0, v = 0;
        for (int j = 0; j < __size; j++) {
            if ((i >> j) & 1)
                w += vec[j].W, v += vec[j].V;
        }
        if (w <= M)
            ret.push_back(ii(w, v));
    }

    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, M;
    cin >> n >> M;

    vector<ii> a(n / 2), b(n - n / 2);
    for (ii& gold: a) cin >> gold.W >> gold.V;
    for (ii& gold: b) cin >> gold.W >> gold.V;

    vector<ii> prefSet(Generate(a, M));
    vector<ii> suffSet(Generate(b, M));

    int res = 0, maxVal = 0;
    for (int i = prefSet.size() - 1, j = 0; i >= 0; i--) {
        while (j < (int)suffSet.size() && prefSet[i].W + suffSet[j].W <= M) {
            maxVal = max(maxVal, suffSet[j].V);
            j++;
        }
        res = max(res, prefSet[i].V + maxVal);
    }

    cout << res << "\n";
}