#include <iostream>
#include <vector>
#include <queue>
#define MAXV 20000
#define INF 100000000
using namespace std;

struct Data {
    int n, w;
    Data() {};
    Data(int n, int w) : n(n), w(w) {};

    bool operator <(const Data other) const {
        return w > other.w;
    }
};

int D[MAXV + 1];
vector<Data> A[MAXV + 1];
bool Visit[MAXV + 1];
int V, E, K;
void dijkstra() {
    priority_queue<Data> pq;
    D[K] = 0;
    pq.push(Data(K, 0));
    while (!pq.empty()) {
        Data curr = pq.top();
        pq.pop();
        if (Visit[curr.n]) continue;
        Visit[curr.n] = true;
        for (int i = 0; i < A[curr.n].size(); i++) {
            int next = A[curr.n][i].n;
            int nextDist = curr.w + A[curr.n][i].w;
            if (nextDist < D[next]) {
                D[next] = nextDist;
                pq.push(Data(next, nextDist));
            } 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E >> K;
    for (int i = 1; i <= V; i++) D[i] = INF;
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(Data(v, w));
    }
    dijkstra();
    for (int i = 1; i <= V; i++) {
        if (Visit[i]) cout << D[i] << '\n';
        else cout << "INF" << '\n';
    }
    return 0;
}