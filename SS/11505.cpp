#include <iostream>
#define MAXN 3000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll IDT[MAXN];
int N, M, K, S = 1;
void update(int n, int value) {
    n += S - 1;
    IDT[n] = value;
    while (n > 0) {
        n /= 2;
        IDT[n] = IDT[n * 2] * IDT[n * 2 + 1] % MOD;
    }
}

ll mul(int l, int r) {
    l += S - 1;
    r += S - 1;
    ll res = 1;
    while (l <= r) {
        if (l % 2 == 1) res = res * IDT[l++] % MOD;
        if (r % 2 == 0) res = res * IDT[r--] % MOD;
        l /= 2;
        r /= 2; 
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    while (S < N) S *= 2;
    fill(IDT, IDT + MAXN, 1);
    for (int i = S; i < S + N; i++) cin >> IDT[i];
    for (int i = S - 1; i > 0; i--) IDT[i] = IDT[i * 2] * IDT[i * 2 + 1] % MOD;
    int a, b, c;
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) update(b, c);
        else cout << mul(b, c) << '\n';
    }
    return 0;
}