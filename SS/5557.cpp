#include <iostream>
using namespace std;

#define MAXN 100
#define MAXNUM 20
long long DP[MAXN + 1][MAXNUM + 1];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int data[MAXN + 1];
    for (int i = 1; i <= n; i++) cin >> data[i];
    DP[1][data[1]] = 1;
    for (int i = 2; i < n; i++) {
        for (int j = 0; j <= 20; j++) {
            if (DP[i - 1][j]) {
                if (j + data[i] <= 20) DP[i][j + data[i]] += DP[i - 1][j];
                if (j - data[i] >= 0) DP[i][j - data[i]] += DP[i - 1][j];
            }
        }
    }
    cout << DP[n - 1][data[n]] << '\n';
    return 0;
}