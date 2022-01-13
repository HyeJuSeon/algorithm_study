#include <iostream>
#define MAXN 100000
using namespace std;

int DP[MAXN + 1];
int N, M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> DP[i];
        DP[i] += DP[i - 1];
    }
    while (M--) {
        int i, j;
        cin >> i >> j;
        cout << DP[j] - DP[i - 1] << '\n';
    }
    return 0;
}