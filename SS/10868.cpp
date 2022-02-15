#include <iostream>
#define MAXN 300000
#define INF 1000000001
using namespace std;

int IDT[MAXN];
int N, M, S = 1;
int getMin(int l, int r) {
    l += S - 1;
    r += S - 1;
    int res = INF;
    while (l <= r) {
        if (l % 2 == 1) res = min(res, IDT[l++]);
        if (r % 2 == 0) res = min(res, IDT[r--]);
        l /= 2;
        r /= 2;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while (S < N) S *= 2;
    for (int i = S; i < S + N; i++) cin >> IDT[i];
    for (int i = S - 1; i > 0; i--) IDT[i] = min(IDT[i * 2], IDT[i * 2 + 1]);
    int a, b;
    while (M--) {
        cin >> a >> b;
        cout << getMin(a, b) << '\n';
    }
    return 0;
}