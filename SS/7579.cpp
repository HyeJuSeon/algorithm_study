#include <iostream>
#define MAXN 100
using namespace std;

int A[MAXN+ 1];
int Cost[MAXN + 1];
int DP[MAXN + 1][MAXN * MAXN + 1];
int N, M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> A[i];
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> Cost[i];
        sum += Cost[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j >= Cost[i]) DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - Cost[i]] + A[i]);
            else DP[i][j] = DP[i - 1][j];
        }
    }
    for (int i = 0; i <= sum; i++) {
        if (DP[N][i] >= M) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}