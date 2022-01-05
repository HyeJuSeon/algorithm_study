#include <bits/stdc++.h>
using namespace std;

#define MAX 2500000 // leaf node 수 * 2
typedef long long ll;

int leaf = 1;
ll Data[MAX];
void update(int b, ll c) {
    b += leaf - 1;
    c -= Data[b];
    while (b > 0) {
        Data[b] += c;
        b /= 2;
    }
}

ll sum(int l, int r) {
    ll res = 0;
    l += leaf - 1;
    r += leaf - 1;
    while (l <= r) {
        if (l % 2 == 1) res += Data[l];
        if (r % 2 == 0) res += Data[r];
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    while (leaf < n) leaf *= 2;
    for (int i = leaf; i < leaf + n; i++) cin >> Data[i];
    for (int i = leaf - 1; i > 0; i--) Data[i] = Data[i * 2] + Data[i * 2 + 1];
    for (int i = 0; i < m + k; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        if (a == 1) update(b, c);
        else if (a == 2) cout << sum(b, c) << '\n';
    }
    return 0;
}