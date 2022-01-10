#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 32000
int Indegree[MAXN + 1];
vector<int> order[MAXN + 1];
int N, M;
void topologySort() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!Indegree[i]) q.push(i);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int j  = 0; j < order[x].size(); j++) {
            int y = order[x][j];
            if (!(--Indegree[y])) q.push(y);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        order[a].push_back(b);
        Indegree[b]++;
    }
    topologySort();
    return 0;
}