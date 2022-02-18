#include <iostream>
#define MAXN 101
using namespace std;

int DP[MAXN][MAXN];
int N, M;
void floydwarshall() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (DP[i][k] == DP[k][j] && DP[i][k])
                    DP[i][j] = DP[i][k];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        DP[a][b] = 1;
        DP[b][a] = -1;
    }
    floydwarshall();
    for (int i = 1; i <= N; i++) {
        int ans = 0;
        for (int j = 1; j <= N; j++) {
            if (!DP[i][j] && i != j) ans++; 
        }
        cout << ans << '\n';
    }
    return 0;
}