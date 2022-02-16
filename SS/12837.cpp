#include <iostream>
#define MAXN 3000000
typedef long long ll;
using namespace std;

ll IDT[MAXN];
int N, Q, S = 1;
void add(int idx, ll value) { // value로 변경x, 추가o
    idx += S - 1;
    while (idx > 0) {
        IDT[idx] += value;
        idx /= 2;
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
    int a, b, c;
    while (Q--) {
        cin >> a >> b >> c;
        if (a == 1) add(b, c);
        else cout << sum(b, c) << '\n';
    }
    return 0;
}