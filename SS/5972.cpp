#include <iostream>
#include <vector>
#include <queue>
#define MAXN 50001
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

int N, M;
int D[MAXN];
vector<Data> A[MAXN];
bool Visit[MAXN];
void dijkstra() {
    priority_queue<Data> pq;
    pq.push(Data(1, 0));
    D[1] = 0;
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    fill(D, D + MAXN, INF);
    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        A[a].push_back(Data(b, c));
        A[b].push_back(Data(a, c));
    }
    dijkstra();
    cout << D[N];
    return 0;
}