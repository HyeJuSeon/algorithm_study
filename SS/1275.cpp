#include <bits/stdc++.h>
using namespace std;

#define MAXN 300000
typedef long long ll;
ll Data[MAXN];
int leaf = 1;
void update(int a, ll b) {
    a += leaf - 1;
    b -= Data[a];
    while (a > 0) {
        Data[a] += b;
        a /= 2;
    }
}

ll sum(int x, int y) {
    ll res = 0;
    x += leaf - 1;
    y += leaf - 1;
    while (x <= y) {
        if (x % 2 == 1) res += Data[x++];
        if (y % 2 == 0) res += Data[y--];
        x /= 2;
        y /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    while (leaf < n) leaf *= 2;
    for (int i = leaf; i < n + leaf; i++) cin >> Data[i];
    for (int i = leaf - 1; i > 0; i--) Data[i] = Data[i * 2] + Data[i * 2 + 1];
    while (q--) {
        int x, y, a;
        ll b;
        cin >> x >> y >> a >> b;
        if (x < y) cout << sum(x, y) << '\n';
        else cout << sum(y, x) << '\n';
        update(a, b);
    }
    return 0;
}