#include <iostream>
#include <vector>
#include <queue>
#define MAXN 801
#define INF 1000000000
using namespace std;

struct Data {
    int n, w;
    Data() {};
    Data(int n, int w): n(n), w(w) {};

    bool operator < (const Data other) const {
        return w > other.w;
    }
};

int D[MAXN];
bool Visit[MAXN];
vector<Data> A[MAXN];
int N, E, V1, V2;
void dijkstra(int s) {
    priority_queue<Data> pq;
    pq.push(Data(s, 0));
    D[s] = 0;
    while (!pq.empty()) {
        Data curr = pq.top();
        pq.pop();
        if (Visit[curr.n]) continue;
        Visit[curr.n] = true;
        for (int i = 0; i < A[curr.n].size(); i++) {
            int next = A[curr.n][i].n;
            int nextDist = curr.w + A[curr.n][i].w;
            if (D[next] > nextDist) {
                D[next] = nextDist;
                pq.push(Data(next, nextDist));
            }
        }
    }
}

void init() {
    fill(D, D + MAXN, INF);
    fill(Visit, Visit + MAXN, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> E;
    int a, b, c;
    while (E--) {
        cin >> a >> b >> c;
        A[a].push_back(Data(b, c));
        A[b].push_back(Data(a, c));
    }
    cin >> V1 >> V2;
    int sNv1, sNv2, v1Nn, v1Nv2, v2Nn;
    init();
    dijkstra(1);
    sNv1= D[V1]; 
    sNv2 = D[V2]; 
    init();
    dijkstra(V1);
    v1Nn = D[N]; 
    v1Nv2 = D[V2]; 
    init();
    dijkstra(V2);
    v2Nn = D[N];
    long long res = min(sNv1 + v1Nv2 + v2Nn, sNv2 + v1Nv2 + v1Nn);
    if (res >= INF || res < 0) cout << -1;
    else cout << res;
    return 0;
}