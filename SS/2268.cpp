#include <iostream>
#define MAXN 1000000
typedef long long ll;
using namespace std;

ll IDT[MAXN * 3];
int N, M, Start = 1;
void update(int i, ll value) {
    i += Start - 1;
    value -= IDT[i];
    while (i > 0) {
        IDT[i] += value;
        i /= 2;
    }
}

ll sum(int l, int r) {
    l += Start - 1;
    r += Start - 1;
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

    cin >> N >> M;
    while (Start < N) Start *= 2;
    int op, i;
    ll j;
    while (M--) {
        cin >> op >> i >> j;
        if (op == 0) {
            if (i < j) cout << sum(i, j) << '\n';
            else cout << sum(j, i) << '\n';
        }
        else update(i, j);
    }
    return 0;
}