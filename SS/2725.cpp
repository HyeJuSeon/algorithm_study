#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001
bool Visit[MAXN + 1];
int DP[MAXN + 1];
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int eulerPhi(int n) {
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (gcd(n, i) == 1) res++;
    }
    return res;
}

int main() {
    for (int i = 2; i <= MAXN; i++) {
        if (Visit[i]) continue;
        for (int j = i * i; j <= MAXN; j += i) Visit[j] = true;
    }
    DP[1] = 3;
    for (int i = 2; i <= MAXN; i++) DP[i] = DP[i - 1] + eulerPhi(i) * 2;

    int C, N;
    cin >> C;
    while (C--) {
        cin >> N;
        cout << DP[N] << '\n';
    }
    return 0;
}