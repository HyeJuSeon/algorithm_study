#include <iostream>
#define MAXN 1000000
typedef long long ll;
using namespace std;

ll IDT[3000000];
int N, M, K, Start = 1;
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

    cin >> N >> M >> K;
    while (Start < N) Start *= 2;
    for (int i = Start; i < Start + N; i++) cin >> IDT[i];
    for (int i = Start - 1; i > 0; i--) IDT[i] = IDT[i * 2] + IDT[i * 2 + 1];
    for (int i = 0; i < M + K; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        if (a == 1) update(b, c);
        else cout << sum(b, c) << '\n';
    }
    return 0;
}
