#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10004
#define MAX_M 30

int n, m;
bool coin[MAX_N];
int h[MAX_N], btn[MAX_N];
int base;

void Try(int b) {

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(NULL));

    for (int i = 1; i <= n; i++)
        h[i] = rand() % 100 + 1;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        bool c;
        cin >> c;
        if (c)
            base += h[i];
    }

    for (int i = 1; i <= m; i++) {
        int l, c;
        cin >> l;
        while (l--) {
            cin >> c;
            btn[i] ^= h[c];
        }
    }

    Try(1);
}