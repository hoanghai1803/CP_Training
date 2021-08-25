#include <bits/stdc++.h>

using namespace std;

#define MAX_N 2002

struct Score {
    int x, y, z;
    bool operator < (Score rhs) {
        vector<int> powA = {x, y, z};
        vector<int> powB = {rhs.x, rhs.y, rhs.z};
        sort(powA.begin(), powA.end());
        sort(powB.begin(), powB.end());

        if (powA[2] == powA[1])
            powA[2]++, powA[1] = powA[0], powA[0] = 0;
        if (powB[2] == powB[1])
            powB[2]++, powB[1] = powB[0], powB[0] = 0;
        
        if (powA[2] > powB[2])
            return true;
        if (powA[2] < powB[2])
            return false;
        if (powA[1] > powB[1])
            return true;
        if (powA[1] < powB[1])
            return false;
        if (powA[0] > powB[0])
            return true;
        return false;
    }

    bool operator == (Score rhs) {
        vector<int> powA = {x, y, z};
        vector<int> powB = {rhs.x, rhs.y, rhs.z};
        sort(powA.begin(), powA.end());
        sort(powB.begin(), powB.end());

        if (powA[2] == powA[1])
            powA[2]++, powA[1] = powA[0], powA[0] = 0;
        if (powB[2] == powB[1])
            powB[2]++, powB[1] = powB[0], powB[0] = 0;

        for (int i = 0; i < 3; i++)
            if (powA[i] != powB[i])
                return false;
        return true;
    }   
};

int n, p, a;
Score ranking[MAX_N];
vector<Score> scores;

bool Check_1(int _rank, Score score_pre, Score score_curr) {
    int i = scores.size() - 1, j = 1;

    for (; i >= 0; i--) {
        if (score_pre < scores[i] || score_pre == scores[i]) {
            j++;
            continue;
        }
        i--;
        break;
    }

    for (; i >= 0 && j <= n; i--) {
        while (j <= n) {
            Score score_temp = scores[i];
            score_temp.z = j;
            j++;
            if (score_temp < score_curr)
                break;
        }
    }

    if (j + 1 >= _rank)
        return true;
    return false;
}

bool Check_2(int _rank, Score score_pre, Score score_curr) {
    int i = scores.size() - 1, j = 2;

    for (; i >= 0; i--) {
        if (score_pre < scores[i]) {
            j++;
            continue;
        }
        i--;
        break;
    }

    for (; i >= 0 && j <= n; i--) {
        while (j <= n) {
            Score score_temp = scores[i];
            score_temp.z = j;
            j++;
            if (score_temp < score_curr)
                break;
        }
    }

    if (j + 1 >= _rank)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        ranking[i].x = p;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a;
        ranking[i].y = a;
        scores.push_back(ranking[i]);
    }

    sort(scores.begin(), scores.end());

    for (int i = 1; i <= n; i++) {
        Score score_curr = ranking[i];

        score_curr.z = 1;
        int L = 1, R = n;
        while (L + 1 <= R) {
            if (L + 1 == R) {
                cout << (Check_1(L, ranking[i], score_curr) ? L : R) << " ";
                break;
            }

            int M = (L + R) >> 1;
            if (Check_1(M, ranking[i], score_curr))
                R = M;
            else 
                L = M;
        }

        score_curr.z = n;
        int L = 1, R = n;
        while (L + 1 <= R) {
            if (L + 1 == R) {
                cout << (Check_2(R, ranking[i], score_curr) ? R : L) << "\n";
                break;
            }

            int M = (L + R) >> 1;
            if (Check_2(M, ranking[i], score_curr))
                L = M;
            else 
                R = M;
        }
    }
}