#include <iostream>
using namespace std;

#define MAXN 30
int DP[MAXN + 1][MAXN + 1];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        DP[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            DP[i][0] = 1;
            for (int j = 1; j <= i; j++) DP[i][j] = DP[i - 1][j] + DP[i - 1][j - 1];
        }
        cout << DP[m][n] << '\n';
    }
    return 0;
}