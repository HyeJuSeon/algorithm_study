#include <iostream>
#include <vector>
#include <queue>
#define MAXN 1001
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

int Dist[MAXN];
vector<Data> A[MAXN];
bool Visit[MAXN];
int N, M, S, D;
void dijkstra() {
    priority_queue<Data> pq;
    pq.push(Data(S, 0));
    Dist[S] = 0;
    while (!pq.empty()) {
        Data curr = pq.top();
        pq.pop();
        if (Visit[curr.n]) continue;
        Visit[curr.n] = true;
        for (int i = 0; i < A[curr.n].size(); i++) {
            int next = A[curr.n][i].n;
            int nextDist = curr.w + A[curr.n][i].w;
            if (Dist[next] > nextDist) {
                Dist[next] = nextDist;
                pq.push(Data(next, nextDist));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    fill(Dist, Dist + MAXN, INF);
    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        A[a].push_back(Data(b, c));
    }
    cin >> S >> D;
    dijkstra();
    cout << Dist[D];
    return 0;
}