#include <iostream>
#define MAXN 501
#define INF 2000000000
using namespace std;

int M[MAXN][2];
int DP[MAXN][MAXN]; // x~y번 행렬의 최소 연산 횟수
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> M[i][0] >> M[i][1];
    for (int m = 1; m < N; m++) {
        for (int i = 0; i < N - m; i++) {
            int j = m + i;
            DP[i][j] = INF;
            for (int k = i; k < j; k++) {
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k + 1][j] + M[i][0] * M[k][1] * M[j][1]);
            }
        }
    }
    cout << DP[0][N - 1];
    return 0;
}
