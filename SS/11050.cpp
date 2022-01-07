#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) res *= i;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    cout << factorial(n) / (factorial(k) * factorial(n - k));
    return 0;
}