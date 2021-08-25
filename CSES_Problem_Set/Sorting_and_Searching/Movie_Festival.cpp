// Author: __BruteForce__
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 200005

int n;
pair<int, int> movies[MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> movies[i].second >> movies[i].first;
    sort(movies, movies + n);

    int curr_end = 0, numMovies = 0;
    for (int i = 0; i < n; i++)
        if (movies[i].second >= curr_end) {
            curr_end = movies[i].first;
            numMovies++;
        }

    cout << numMovies << "\n";
}