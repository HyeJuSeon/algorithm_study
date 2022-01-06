#include <iostream>
using namespace std;

#define MAXN 50000
#define MAX 120000
typedef long long ll;
int year[MAXN];
ll IDT[MAX];
int n, m, leaf = 1;
int max_rain(int l, int r) {
    if (l >= n || r >= n) return 0;
    l += leaf; // year 배열이 0부터 시작하기 때문에 -1 생략
    r += leaf;
    ll max_r = 0;
    while (l <= r) {
        if (l % 2 == 1) max_r = max(max_r, IDT[l++]);
        if (r % 2 == 0) max_r = max(max_r, IDT[r--]);
        l /= 2;
        r /= 2;
    }
    return max_r;
}

int solve(int Y, int X) { // 1) X~Y 강수량 알려짐 2) X 강 <= Y 강 3) Z 강 < X 강
    int y_idx = lower_bound(year, year + n, Y) - year;
    int x_idx = lower_bound(year, year + n, X) - year;
    bool exist_y = (y_idx < n && year[y_idx] == Y);
    bool exist_x = (x_idx < n && year[x_idx] == X);
    if (exist_x && exist_y && IDT[y_idx + leaf] < IDT[x_idx + leaf]) return 0; // 2) 
    int Z = max_rain(lower_bound(year, year + n, Y + 1) - year, x_idx - 1);
    if (exist_x && IDT[x_idx + leaf] <= Z) return 0; // 3)
    if (exist_y && IDT[y_idx + leaf] <= Z) return 0; // 2)
    if (exist_x && exist_y && Y - X == y_idx - x_idx) return 1; // 2) 3)은 위에서 걸러짐
    return 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (leaf < n) leaf *= 2;
    for (int i = 0; i < n; i++) cin >> year[i] >> IDT[i + leaf];
    for (int i = leaf - 1; i > 0; i--) IDT[i] = max(IDT[i * 2], IDT[i * 2 + 1]); 
    cin >> m;
    int X, Y;
    while (m--) {
        cin >> Y >> X;
        int res = solve(Y, X);
        if (res == 0) cout << "false" << '\n';
        else if (res == 1) cout << "true" << '\n';
        else cout << "maybe" << '\n';
    }
    return 0;
}