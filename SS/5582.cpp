#include <iostream>
#include <string>
#define MAXN 4000
using namespace std;

int DP[MAXN + 1][MAXN + 1];
string Str1, Str2;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> Str1 >> Str2;
    int res = 0;
    for (int i = 0; i < Str1.length(); i++) {
        for (int j = 0; j < Str2.length(); j++) {
            if (Str1[i] == Str2[j]) {
                DP[i + 1][j + 1] = DP[i][j] + 1;
                res = max(res, DP[i + 1][j + 1]);
            }
        }
    }
    cout << res << '\n';
    return 0;
}