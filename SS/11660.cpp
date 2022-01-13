#include <iostream>
#define MAXN 1024
using namespace std;

int DP[MAXN + 1][MAXN + 1];
int Mat[MAXN + 1][MAXN + 1];
int N, M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> Mat[i][j];
            DP[i][j] = DP[i][j - 1] + DP[i - 1][j] - DP[i - 1][j - 1] + Mat[i][j];
        }
    }
    int x1, x2, y1, y2;
    while (M--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << DP[x2][y2] - DP[x2][y1 - 1]- DP[x1 - 1][y2] + DP[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}