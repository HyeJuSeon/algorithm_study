#include <iostream>
using namespace std;

#define MAXN 100
#define MAXK 1000000000
int DP[MAXN * 2 + 1][MAXN + 1];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    DP[0][0] = 1;
    n += m;
    for (int i = 1; i <= n; i++) {
        DP[i][0] = 1;
        for (int j = 1; j <= i && j <= m; j++) {
            DP[i][j] = DP[i - 1][j] + DP[i - 1][j - 1];
            if (DP[i][j] > MAXK) DP[i][j] = MAXK + 1;
        }
    }
    if (DP[n][m] < k) {
        cout << -1;
        return 0;
    }
    while (n) {
        if (DP[n - 1][m] >= k) cout << 'a';
        else {
            cout << 'z';
            k -= DP[n - 1][m--];
        }
        n--;
    }
    return 0;
}