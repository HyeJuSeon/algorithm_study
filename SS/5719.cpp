#include <iostream>
#include <vector>
#include <queue>
#define MAXN 500
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
bool IsPath[MAXN][MAXN]; // 최단 경로 포함 여부 저장
vector<Data> A[MAXN];
vector<int> Par[MAXN]; // 각 노드의 최단 경로의 바로 이전 노드
int N, M, S, D;
void dijkstra(int seq) {
    priority_queue<Data> pq;
    pq.push(Data(S, 0));
    Dist[S] = 0;
    while (!pq.empty()) {
        Data curr = pq.top();
        pq.pop();
        int next, nextDist;
        for (int i = 0; i < A[curr.n].size(); i++) {
            next = A[curr.n][i].n;
            if (IsPath[curr.n][next]) continue;
            nextDist = curr.w + A[curr.n][i].w;
            if (Dist[next] > nextDist) {
                Dist[next] = nextDist;
                pq.push(Data(next, nextDist));
                if (seq == 1) {
                    Par[next].clear();
                    Par[next].push_back(curr.n);
                }
            }
            else if (seq == 1) {
                if (Dist[next] == nextDist) Par[next].push_back(curr.n);
            }
        }
    }
}

void removePath(int start, int dest) {
    if (start == dest) return;
    for (int i = 0; i < Par[dest].size(); i++) {
        if (IsPath[Par[dest][i]][dest]) continue;
        IsPath[Par[dest][i]][dest] = true;
        removePath(start, Par[dest][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int u, v, p;
    while (1) {
        cin >> N >> M;
        if (!N && !M) break;
        cin >> S >> D;
        fill(Dist, Dist + N, INF);
        fill(IsPath[0], IsPath[N], 0);
        for (int i = 0; i < N; i++) A[i].clear();

        while (M--) {
            cin >> u >> v >> p;
            A[u].push_back(Data(v, p));
        }
        dijkstra(1);
        if (Dist[D] == INF) {
            cout << -1 << '\n';
            continue;
        }
        
        removePath(S, D);
        fill(Dist, Dist + N, INF);
        dijkstra(2);
        if (Dist[D] == INF) cout << -1 << '\n';
        else cout << Dist[D] << '\n';
    }
    return 0;
}
