#include <iostream>
#define MAXN 100001
using namespace std;

int DP[MAXN];
int N, M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> DP[i];
        DP[i] += DP[i - 1];
    }
    int a, b;
    while (M--) {
        cin >> a >> b;
        cout << DP[b] - DP[a - 1] << '\n';
    }
    return 0;
}
