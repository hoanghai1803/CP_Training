// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100005

int n, q;
int a[MAX_N];
vector<int> val[MAX_N];
int lo[MAX_N], hi[MAX_N], ql[MAX_N], qr[MAX_N];
stack<int> to_check[MAX_N];
int bit[MAX_N];

void update(int p) {
    for (; p <= n; p += p & -p) bit[p]++;
}

int get(int p) {
    int sum = 0;
    for (; p; p -= p & -p) sum += bit[p];
    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val[a[i]].push_back(i);
    }
    for (int i = 1; i <= q; i++) {
        cin >> ql[i] >> qr[i];
        lo[i] = 1, hi[i] = MAX_N - 1;
    }

    bool changed = true;
    while (changed) {
        // Reset
        changed = false;
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= q; i++)
            if (lo[i] != hi[i]) to_check[(lo[i] + hi[i]) >> 1].push(i);

        for (int mid = 1; mid < MAX_N; mid++) {
            for (int pos : val[mid]) update(pos);

            while (to_check[mid].size()) {
                changed = true;
                int idx = to_check[mid].top();
                to_check[mid].pop();

                int cnt = get(qr[idx]) - get(ql[idx] - 1);
                int range = qr[idx] - ql[idx] + 1;
                if (cnt >= (range + 1) / 2)
                    hi[idx] = mid;
                else
                    lo[idx] = mid + 1;
            }
        }
    }

    for (int i = 1; i <= q; i++) cout << lo[i] << "\n";
}