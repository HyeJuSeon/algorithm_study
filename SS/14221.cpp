#include <iostream>
#include <vector>
#include <queue>
#define MAXN 5001
#define INF 2000000000
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
int Start[MAXN];
int Dest[MAXN];
int N, M, P, Q;
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        A[a].push_back(Data(b, c));
        A[b].push_back(Data(a, c));
    }
    cin >> P >> Q;
    for (int i = 0; i < P; i++) cin >> Start[i];
    for (int i = 0; i < Q; i++) cin >> Dest[i];
    int res, minDist = INF;
    for (int i = 0; i < P; i++) {
        fill(D, D + MAXN, INF);
        fill(Visit, Visit + MAXN, 0);
        dijkstra(Start[i]);
        for (int j = 0; j < Q; j++) {
            if (minDist > D[Dest[j]]) {
                minDist = D[Dest[j]];
                res = Start[i];
            }
            else if (minDist == D[Dest[j]] && res > Start[i]) res = Start[i]; 
        }
    }
    cout << res;
    return 0;
}