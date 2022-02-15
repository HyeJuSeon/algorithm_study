#include <iostream>
#define MAXN 300000
#define INF 1000000001
using namespace std;

struct Data {
    int min, max;
    Data() {};
    Data(int min, int max): min(min), max(max) {};
};

Data IDT[MAXN];
int N, M, S = 1;
void get(int l, int r) {
    l += S - 1;
    r += S - 1;
    int Min = INF, Max = 0;
    while (l <= r) {
        if (l % 2 == 1) {
            Min = min(Min, IDT[l].min);
            Max = max(Max, IDT[l++].max);
        }
        if (r % 2 == 0) {
            Min = min(Min, IDT[r].min);
            Max = max(Max, IDT[r--].max);
        }
        l /= 2;
        r /= 2;
    }
    cout << Min << ' ' << Max << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while (S < N) S *= 2;
    int x;
    for (int i = S; i < S + N; i++) {
        cin >> x;
        IDT[i] = Data(x, x);
    }
    for (int i = S - 1; i > 0; i--) {
        IDT[i].min = min(IDT[i * 2].min, IDT[i * 2 + 1].min);
        IDT[i].max = max(IDT[i * 2].max, IDT[i * 2 + 1].max);
    }
    int a, b;
    while (M--) {
        cin >> a >> b;
        get(a, b);
    }
    return 0;
}
