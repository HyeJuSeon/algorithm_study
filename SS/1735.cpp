#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    int deno = lcm(b1, b2);
    a1 *= deno / b1;
    a2 *= deno / b2;
    int nume = a1 + a2;
    int g = gcd(nume, deno);
    cout << nume / g << ' ' << deno / g << '\n';
    return 0;
}