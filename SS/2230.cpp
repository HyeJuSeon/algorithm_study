#include <iostream>
#include <algorithm>
#define MAXN 100000
#define INF 2000000001
using namespace std;

int A[MAXN];
int N, M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N);
    int r = 0, res = INF;
    for (int l = 0; l < N; l++) {
        while (r < N && A[r] - A[l] < M) r++;
        if (r == N) break;
        res = min(res, A[r] - A[l]);
    }
    cout << res;
    return 0;
}