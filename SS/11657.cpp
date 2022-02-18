#include <iostream>
#define MAXN 501
#define MAXM 6000
#define INF 2000000000
typedef long long ll;
using namespace std;

struct Data {
    int x, y, w;
    Data() {};
    Data(int x, int  y, int w): x(x), y(y), w(w) {};
};

ll D[MAXN];
Data E[MAXM];
int N, M;
void bellmanford() {
    D[1] = 0;
    for (int i = 1; i < N; i++) { // cycle 확인할 때 한 번 더 돌림
        for (int j = 0; j < M; j++) {
            if (D[E[j].x] == INF) continue;
            if (D[E[j].y] > D[E[j].x] + E[j].w) D[E[j].y] = D[E[j].x] + E[j].w;
        }
    }
    bool isCycle = false;
    for (int i = 0; i < M; i++) {
        if (D[E[i].x] == INF) continue;
        if (D[E[i].y] > D[E[i].x] + E[i].w) {
            D[E[i].y] = D[E[i].x] + E[i].w;
            isCycle = true;
        }
    }
    if (isCycle) cout << -1;
    else {
        for (int i = 2; i <= N; i++) {
            if (D[i] == INF) cout << -1 << '\n';
            else cout << D[i] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        E[i] = Data(a, b, c);
    }
    fill(D, D + N + 1, INF);
    bellmanford();
    return 0;
}
