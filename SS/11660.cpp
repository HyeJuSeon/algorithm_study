#include <iostream>
#define MAXN 1025
using namespace std;

int DP[MAXN][MAXN];
int N, M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> DP[i][j];
            DP[i][j] += DP[i][j - 1] + DP[i - 1][j] - DP[i - 1][j - 1];
        }
    }
    int a, b, c, d;
    while (M--) {
        cin >> a >> b >> c >> d;
        cout << DP[c][d] - DP[a - 1][d] - DP[c][b - 1] + DP[a - 1][b - 1] << '\n';
    }
    return 0;
}
