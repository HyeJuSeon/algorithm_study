#include <iostream>
#define MAXN 500
#define MAXM 6000
#define INF 1000000000
using namespace std;

struct Data {
    int n1, n2, w;
    Data() {};
    Data(int n1, int n2, int w) : n1(n1), n2(n2), w(w) {};
};

long long D[MAXN + 1];
Data A[MAXM];
int N, M;
void bellmanford() {
    D[1] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (D[A[j].n1] == INF) continue;
            if (D[A[j].n2] > D[A[j].n1] + A[j].w) D[A[j].n2] = D[A[j].n1] + A[j].w;
        }
    }
    bool isCycle = false;
    for (int i = 0; i < M; i++) {
        if (D[A[i].n1] == INF) continue;
        if (D[A[i].n2] > D[A[i].n1] + A[i].w) {
            isCycle = true;
            break;
        }
    }
    if (isCycle) cout << -1 << '\n';
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
        A[i] = Data(a, b, c);
    }
    for (int i = 1; i <= N; i++) D[i] = INF;
    bellmanford();
    return 0;
}