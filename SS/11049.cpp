#include <iostream>
#define MAXN 500
#define INF 1000000000
using namespace std;

int DP[MAXN][MAXN]; // DP[x][y]: x ~ y까지 곱했을 떄 최소값
int A[MAXN][2]; 
int N;
int dfs (int x, int y) {
    if (x == y) return 0;
    if (DP[x][y] != INF) return DP[x][y];
    for (int i = x; i < y; i++) 
        DP[x][y] = min(DP[x][y], dfs(x, i) + dfs(i + 1, y) + A[x][0] * A[i][1] * A[y][1]);
    return DP[x][y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i][0] >> A[i][1];
        for (int j = 0; j < N; j++) DP[i][j] = INF;
    }
    cout << dfs(0, N - 1);
    return 0;
}
