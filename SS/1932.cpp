#include <iostream>
#define MAXN 501
using namespace std;

int DP[MAXN][MAXN];
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> DP[i][j];
            if (j == 1) DP[i][j] += DP[i - 1][j];
            else if (j == i) DP[i][j] += DP[i - 1][j - 1];
            else DP[i][j] += max(DP[i - 1][j - 1], DP[i - 1][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, DP[N][i]);
    cout << ans;
    return 0;
}
