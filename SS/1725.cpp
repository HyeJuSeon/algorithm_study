#include <iostream>
#include <stack>
#define MAXN 100002
using namespace std;

int N, ANS = 0;
int H[MAXN];
stack<int> S;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> H[i];
    S.push(0);
    for (int i = 1; i <= N + 1; i++) {
        while (!S.empty() && H[S.top()] > H[i]) {
            int h = H[S.top()];
            S.pop();
            ANS = max(ANS, h * (i - S.top() - 1));
        }
        S.push(i);
    }
    cout << ANS;
    return 0;
}