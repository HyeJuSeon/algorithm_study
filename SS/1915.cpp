#include <iostream>
#define MAXN 1001
using namespace std;

int DP[MAXN][MAXN];
char Input[MAXN];
int N, M, Ans = 0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> Input;
        for (int j = 1; j <= M; j++) {
            DP[i][j] = Input[j - 1] - '0';
            if (DP[i][j]) {
                DP[i][j] += min(DP[i - 1][j - 1], min(DP[i][j - 1], DP[i - 1][j]));
                Ans = max(Ans, DP[i][j]);
            }
        }
    }
    cout << Ans * Ans;
    return 0;
}
