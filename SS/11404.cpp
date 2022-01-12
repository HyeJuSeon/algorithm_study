#include <iostream>
#define MAXN 100
#define INF 1000000000
using namespace std;

int DP[MAXN + 1][MAXN + 1];
int N, M;
void floydwarshall() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) DP[i][j] = 0;
            else DP[i][j] = INF;
        }
    }
    int a, b, c;
    while(M--) {
        cin >> a >> b >> c;
        DP[a][b] = min(DP[a][b], c);
    }
    floydwarshall();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (DP[i][j] == INF) cout << 0 << ' ';
            else cout << DP[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}