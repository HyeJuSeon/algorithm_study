#include <bits/stdc++.h>
using namespace std;

#define MAXN 10
int DP[MAXN + 1][MAXN + 1];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    DP[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        DP[i][0] = 1;
        for (int j = 1; j <= i && j <= k; j++) DP[i][j] = DP[i - 1][j] + DP[i - 1][j - 1];
    }
    cout << DP[n][k];
    return 0;
}