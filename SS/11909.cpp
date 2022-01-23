#include <iostream>
#include <vector>
#include <queue>
#define MAXN 2223
#define INF 1000000000
using namespace std;

struct Data {
    int n, w;
    Data () {};
    Data (int n, int w): n(n), w(w) {};

    bool operator < (const Data other) const {
        return w > other.w;
    }
};

int N;
int Map[MAXN * MAXN];
vector<Data> A[MAXN * MAXN];
int D[MAXN * MAXN];
bool Visit[MAXN * MAXN];
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

    cin >> N;
    for (int i = 1; i <= N * N; i++) cin >> Map[i];
    for (int i = 1; i < N * N; i++) {
        if (i > N * N - N) {
            if (Map[i] > Map[i + 1]) A[i].push_back(Data(i + 1, 0));
            else A[i].push_back(Data(i + 1, Map[i + 1] - Map[i] + 1));
        }
        else if (i % N == 0) {
            if (Map[i] > Map[i + N]) A[i].push_back(Data(i + N, 0));
            else A[i].push_back(Data(i + N, Map[i + N] - Map[i] + 1));
        }
        else {
            if (Map[i] > Map[i + 1]) A[i].push_back(Data(i + 1, 0));
            else A[i].push_back(Data(i + 1, Map[i + 1] - Map[i] + 1));
            if (Map[i] > Map[i + N]) A[i].push_back(Data(i + N, 0));
            else A[i].push_back(Data(i + N, Map[i + N] - Map[i] + 1));
        }
    }
    fill(D, D + MAXN * MAXN, INF);
    dijkstra();
    cout << D[N * N];
    return 0;
}