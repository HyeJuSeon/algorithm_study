#include <iostream>
#define MAXN 1024
using namespace std;

int DP[MAXN + 1][MAXN + 1];
int N, M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> DP[i][j];
            DP[i][j] += DP[i][j - 1];
        }
    }
    int x1, x2, y1, y2;
    while (M--) {
        int res = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; i++) {
            res += DP[i][y2] - DP[i][y1 - 1];
        }
        cout << res << '\n';
    }
    return 0;
}