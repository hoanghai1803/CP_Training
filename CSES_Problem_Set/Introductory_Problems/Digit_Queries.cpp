#include <bits/stdc++.h>

using namespace std;

void Find(long long k) {
    long long digits = 0;
    long long n = 9;
    int d = 1;
    while (digits + n * d <= k) 
        digits += n * d, n *= 10, d++;

    int dg = (k - digits) % d;
    long long num = n / 9 - 1 + (k - digits - dg) / d; 
    if (!dg) 
        dg = d;
    else    
        num++;

    for (int i = 0; i < d - dg; i++)
        num /= 10;
    cout << num % 10 << "\n";
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        long long k;
        cin >> k;
        Find(k); 
    }
}