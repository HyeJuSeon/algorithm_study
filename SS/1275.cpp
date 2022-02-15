#include <iostream>
#define MAXN 300000
typedef long long ll;
using namespace std;

ll IDT[MAXN];
int N, Q, S = 1;
void update(int n, ll value) {
    n += S - 1;
    value -= IDT[n];
    while (n > 0) {
        IDT[n] += value;
        n /= 2;
    }
}

ll sum(int l, int r) {
    l += S - 1;
    r += S - 1;
    ll res = 0;
    while (l <= r) {
        if (l % 2 == 1) res += IDT[l++];
        if (r % 2 == 0) res += IDT[r--];
        l /= 2;
        r /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    while (S < N) S *= 2;
    for (int i = S; i < S + N; i++) cin >> IDT[i];
    for (int i = S - 1; i > 0; i--) IDT[i] = IDT[i * 2] + IDT[i * 2 + 1];
    int x, y, a;
    ll b;
    while (Q--) {
        cin >> x >> y >> a >> b;
        if (x < y) cout << sum(x, y) << '\n';
        else cout << sum(y, x) << '\n';
        update(a, b);
    }
    return 0;
}
