#include <iostream>
#include <vector>
#define MAXN 501
#define INF 2000000000
using namespace std;

// 사이클 유무를 판단할 때는 INF 비교 연산X -> INF 비교 연산은 어떤 지점에서 부터 거리를 구할 때 쓰임
// 따라서 INF 비교 연산을 하게 되면 단절된 노드끼리 사이클을 형성하는 경우는 알 수 없게 됨
struct Data {
    int x, y, w;
    Data() {};
    Data(int x, int y, int w): x(x), y(y), w(w) {};
};

int D[MAXN];
vector<Data> E;
int T, N, M, W;
void bellmanford() {
    D[1] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < E.size(); j++) {
            if (D[E[j].y] > D[E[j].x] + E[j].w) D[E[j].y] = D[E[j].x] + E[j].w;
        }
    }
    bool isCycle = false;
    for (int i = 0; i < E.size(); i++) {
        if (D[E[i].y] > D[E[i].x] + E[i].w) isCycle = true;
    }
    if (isCycle) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

void init() {
    fill(D, D + MAXN, INF);
    E.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        init();
        cin >> N >> M >> W;
        int a, b, c;
        while (M--) {
            cin >> a >> b >> c;
            E.push_back(Data(a, b, c));
            E.push_back(Data(b, a, c));
        }
        while (W--) {
            cin >> a >> b >> c;
            E.push_back(Data(a, b, -c));
        }
        bellmanford();
    }
    return 0;
}