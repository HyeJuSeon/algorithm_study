#include <iostream>
#define MAXN 500
using namespace std;

int DP[MAXN][MAXN];
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) cin >> DP[i][j];
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) DP[i][0] += DP[i - 1][0];
            else if (j == i) DP[i][j] += DP[i - 1][j - 1];
            else DP[i][j] += max(DP[i - 1][j - 1], DP[i - 1][j]);
        }
    }
    int res = 0;
    for (int i = 0; i < N; i++) res = max(res, DP[N - 1][i]);
    cout << res << '\n';
    return 0;
}