#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
#define MAXM 1000000000
int Data[MAXN];
int n, m;
bool tree(int size) {
    long long h = 0;
    for (int i = 0; i < n; i++) h += max(0, Data[i] - size);
    if (h >= m) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> Data[i];
    int lb = 0, ub = *max_element(Data, Data + n), m, res;
    while (lb + 1 < ub) {
        m = (lb + ub) / 2;
        if (tree(m)) lb = m;
        else ub = m;
    }
    cout << lb;
    return 0;
}