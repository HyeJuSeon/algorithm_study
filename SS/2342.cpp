#include <iostream>
#define MAXN 100000
using namespace std;

int DP[MAXN + 1][5][5];
int P[5][5];
int A[MAXN];
int N;
int solve(int n, int l, int r) {
    if (n == N) return 0;
    if (DP[n][l][r] > 0) return DP[n][l][r];
    int left = solve(n + 1, A[n], r) + P[l][A[n]];
    int right = solve(n + 1, l, A[n]) + P[r][A[n]];
    return DP[n][l][r] = min(left, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    N = 0;
    while (1) {
        cin >> A[N];
        if (A[N] == 0) break;
        N++;
    }
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            P[0][j] = 2;
            if (i == j) P[i][j] = 1;
            else if (abs(i - j) == 2) P[i][j] = 4; 
            else P[i][j] = 3;
        }
    }
    cout << solve(0, 0, 0);
    return 0;
}