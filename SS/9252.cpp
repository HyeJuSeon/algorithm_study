#include <iostream>
#include <vector>
#include <string>
#define MAXN 1000
using namespace std;

int DP[MAXN + 1][MAXN + 1];
string S1, S2;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> S1 >> S2;
    int res = 0;
    for (int i = 1; i <= S1.length(); i++) {
        for (int j = 1; j <= S2.length(); j++) {
            if (S1[i - 1] == S2[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
            else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }
    int idx1 = S1.length();
    int idx2 = S2.length();
    res = DP[idx1][idx2];
    cout << res << '\n';
    if (res > 0) {
        vector<char> v;
        while (idx1 && idx2) {
            if (S1[idx1 - 1] == S2[idx2 - 1]) {
                v.push_back(S1[idx1 - 1]);
                idx1--; 
                idx2--;
            }         
            else {
                if (DP[idx1][idx2] == DP[idx1 - 1][idx2]) idx1--;
                else if (DP[idx1][idx2] == DP[idx1][idx2 - 1]) idx2--;
            }
        }
        while (!v.empty()) {
            cout << v.back();
            v.pop_back();
        }
    }
    return 0;
}