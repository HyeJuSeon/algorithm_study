#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000000
long long  x, y;
int z;
bool change(int game) {
    if ((y + game) * 100 / (x + game) > z) return true;
    else return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;
    z = y * 100 / x;
    int lb = 0, ub = MAX, m;
    if (z >= 99) ub = -1;
    while (lb + 1 < ub) {
        m = (lb + ub) / 2;
        if (change(m)) ub = m;
        else lb = m;
    }
    cout << ub;
    return 0;
}