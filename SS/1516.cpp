#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 500
int Indegree[MAXN + 1];
int T[MAXN + 1];
int DP[MAXN + 1];
vector<int> B[MAXN + 1];
int N;
void solve() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!Indegree[i]) q.push(i);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int j = 0; j < B[x].size(); j++) {
            int y = B[x][j];
            DP[y] = max(DP[y], DP[x] + T[y]);
            if (!(--Indegree[y])) q.push(y);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int b;
        cin >> T[i] >> b;
        DP[i] = T[i];
        while (b != -1) {
            B[b].push_back(i);
            Indegree[i]++;
            cin >> b;
        }
    }
    solve();
    for (int i = 1; i <= N; i++) cout << DP[i] << '\n';
    return 0;
}