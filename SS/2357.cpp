#include <iostream>
#define MAXN 300000
#define INF 1000000001
using namespace std;

int MinIDT[MAXN];
int MaxIDT[MAXN];
int N, M, S = 1;
int getMax(int l, int r) {
    l += S - 1;
    r += S - 1;
    int res = 0;
    while (l <= r) {
        if (l % 2 == 1) res = max(res, MaxIDT[l++]);
        if (r % 2 == 0) res = max(res, MaxIDT[r--]);
        l /= 2;
        r /= 2;
    }
    return res;
}
int getMin(int l, int r) {
    l += S - 1;
    r += S - 1;
    int res = INF;
    while (l <= r) {
        if (l % 2 == 1) res = min(res, MinIDT[l++]);
        if (r % 2 == 0) res = min(res, MinIDT[r--]);
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
    int x;
    for (int i = S; i < S + N; i++) {
        cin >> x;
        MinIDT[i] = x;
        MaxIDT[i] = x;
    }
    for (int i = S - 1; i > 0; i--) {
        MinIDT[i] = min(MinIDT[i * 2], MinIDT[i * 2 + 1]);
        MaxIDT[i] = max(MaxIDT[i * 2], MaxIDT[i * 2 + 1]);
    }
    int a, b;
    while (M--) {
        cin >> a >> b;
        cout << getMin(a, b) << ' ';
        cout << getMax(a, b) << '\n';
    }
    return 0;
}