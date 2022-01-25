#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

int D[MAXN];
bool Visit[MAXN];
vector<Data> A[MAXN];
int N, M, X;
void dijkstra(int s) {
    priority_queue<Data> pq;
    pq.push(Data(s, 0));
    D[s] = 0;
    while (!pq.empty()) {
        Data curr = pq.top();
        pq.pop();
        if(Visit[curr.n]) continue;
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
    
    cin >> N >> M >> X;
    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        A[a].push_back(Data(b, c));
    }
    fill(D, D + MAXN, INF);
    dijkstra(X);
    int xD[MAXN];
    copy(D, D + MAXN, xD);
    int res = 0;
    for (int i = 1; i <= N; i++) {
        if (i == X) continue;
        fill(D, D + MAXN, INF);
        fill(Visit, Visit + MAXN, 0);
        dijkstra(i);
        res = max(res, xD[i] + D[X]);
    }
    cout << res;
    return 0;
}