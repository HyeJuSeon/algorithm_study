#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n, x;
    int res = 0;
    int a[1000000] = {};
    int occur[2000001] = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        occur[a[i]] = 1;
    }
    cin >> x;
    for (int i = 0; i < n; i++) 
        if (occur[x - a[i]]) res++;
    cout << res / 2 << '\n';
    return 0;
}