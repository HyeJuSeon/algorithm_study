#include <iostream>
using namespace std;

#define MAXN 1000000
int Parent[MAXN];
int find(int a) {
    if (Parent[a] == a) return a;
    return Parent[a] = find(Parent[a]);
}

void uni(int a, int b) {
    Parent[find(a)] = find(b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) Parent[i] = i;
    while (m--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) {
            uni(a, b);
        }
        else {
            if (find(a) == find(b)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}
