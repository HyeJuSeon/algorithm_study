#include <bits/stdc++.h>
using namespace std;

#define MAXN 10001
int a[MAXN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    int res = 0, left = 0, right = 0;
    long long sum = a[left];
    while (left <= right && right < n) {
        if (sum == m) {
            res++;
            sum -= a[left++];
            if (left > right) sum += a[++right];
        }
        else if (sum < m) sum += a[++right];
        else {
            sum -= a[left++];
            if (left > right) sum += a[++right];
        }
    }
    cout << res;
    return 0;
}