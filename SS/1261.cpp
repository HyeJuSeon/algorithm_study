#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAXN 101
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
int Maze[MAXN * MAXN];
bool Visit[MAXN * MAXN];
vector<Data> A[MAXN * MAXN];
int N, M;
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
    string maze;
    int cnt = 1;
    for (int i = 0; i < M; i++) {
        cin >> maze;
        for (auto ch : maze) Maze[cnt++] = ch - '0';
    }
    for (int i = 1; i < N * M; i++) {
        if (i % N != 0) A[i].push_back(Data(i + 1, Maze[i + 1]));
        if ((i - 1) % N != 0) A[i].push_back(Data(i - 1, Maze[i - 1]));
        if (i <= N * M - N) A[i].push_back(Data(i + N, Maze[i + N]));
        if (i > N) A[i].push_back(Data(i - N, Maze[i - N]));
        }
    fill(D, D + MAXN * MAXN, INF);
    dijkstra();
    cout << D[N * M];
    return 0;
}