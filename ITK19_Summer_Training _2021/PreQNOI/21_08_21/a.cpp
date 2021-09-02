#include <bits/stdc++.h>

using namespace std;

int main() {    
    int n, base = 1, temp;
    cin >> n;
    for (temp = n; temp >= 10; base *= 10, temp /= 10) {}
    cout << (temp + 1) * base - n << "\n";
}