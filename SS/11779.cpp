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
bool Visit[MAXN];
vector<Data> A[MAXN];
vector<int> P[MAXN];
int N, M, S, D;
void dijkstra(int s) {
    priority_queue<Data> pq;
    pq.push(Data(s, 0));
    Dist[s] = 0;
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
                P[next].clear();
                P[next].push_back(curr.n);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        A[a].push_back(Data(b, c));
    }
    cin >> S >> D;
    fill(Dist, Dist + MAXN, INF);
    dijkstra(S);
    cout << Dist[D] << '\n';
    int prev = D;
    vector<int> path;
    while(1) {
        if (prev == S) break;
        path.push_back(P[prev][0]);
        prev = P[prev][0];
    }
    cout << path.size() + 1 << '\n';
    while (!path.empty()) {
        cout << path.back() << ' ';
        path.pop_back();
    }
    cout << D;
    return 0;
}