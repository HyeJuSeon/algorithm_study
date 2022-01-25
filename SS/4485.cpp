#include <iostream>
#include <vector>
#include <queue>
#define MAXN 125
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

int D[MAXN * MAXN];
int Map[MAXN * MAXN];
bool Visit[MAXN * MAXN];
vector<Data> A[MAXN * MAXN];
int N;
void dijkstra() {
    priority_queue<Data> pq;
    pq.push(Data(0, Map[0]));
    D[0] = Map[0];
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

    int cnt = 1;
    while (1) {
        cin >> N;
        if (N == 0) break;
        fill(D, D + MAXN * MAXN, INF);
        fill(Visit, Visit + MAXN * MAXN, 0);
        for (int i = 0; i < N * N; i++) A[i].clear();
        
        for (int i = 0; i < N * N; i++) cin >> Map[i];
        for (int i = 0; i < N * N - 1; i++) {
            if ((i + 1) % N != 0) A[i].push_back(Data(i + 1, Map[i + 1]));
            if (i % N != 0) A[i].push_back(Data(i - 1, Map[i - 1]));
            if (i < N * N - N) A[i].push_back(Data(i + N, Map[i + N]));
            if (i >= N) A[i].push_back(Data(i - N, Map[i - N]));
        }
        dijkstra();
        cout << "Problem " << cnt++ << ": " << D[N * N - 1] << '\n';
    }
    return 0;
}