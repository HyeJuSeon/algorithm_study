#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[MAXN];
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int left = 0, right = 0, sum = arr[0], res = n + 1;
    while (left <= right && right < n) {
        if (sum < s) sum += arr[++right];
        else {
            res = min(res, right - left + 1);
            sum -= arr[left++];
        }
    }
    if (res == n + 1) res = 0;
    cout << res;
    return 0;
}