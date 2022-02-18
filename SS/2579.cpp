#include <iostream>
#define MAXN 300
using namespace std;

int N;
int S[MAXN];
int DP[MAXN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> S[i];
    DP[0] = S[0];
    DP[1] = S[0] + S[1];
    DP[2] = max(S[0], S[1]) + S[2];
    for (int i = 3; i < N; i++) DP[i] = max(S[i - 1] + DP[i - 3], DP[i - 2]) + S[i];
    cout << DP[N - 1];
    return 0;
}
