#include <iostream>
#define MAXN 1000
using namespace std;

int DP[MAXN + 1][MAXN + 1];
char Input[MAXN + 1];
int N, M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int res = 0;
    for (int i = 1; i <= N; i++) {
        cin >> Input;
        for (int j = 1; j <= M; j++) {
            DP[i][j] = Input[j - 1] - '0';
            if (DP[i][j]) {
                DP[i][j] = min(DP[i - 1][j], min(DP[i][j - 1], DP[i - 1][j - 1])) + 1;
                res = max(res, DP[i][j]);
            }
        }
    }
    cout << res * res << '\n';
    return 0;
}