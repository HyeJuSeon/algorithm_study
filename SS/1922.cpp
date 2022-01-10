#include <iostream>
#include <queue>
using namespace std;

#define MAXN 1000
int Parent[MAXN + 1];
struct Data {
    int n1, n2, cost;
    Data() {};
    bool operator <(const Data other) const {
        return cost > other.cost;
    }
};

int find(int x) {
    if (Parent[x] == x) return x;
    return Parent[x] = find(Parent[x]);
}

void uni(int x, int y) {
    Parent[find(x)] = find(y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) Parent[i] = i;
    priority_queue<Data> pq;
    Data data;
    while (m--) {
        cin >> data.n1 >> data.n2 >> data.cost;
        pq.push(data);
    }
    int cnt = 0;
    int res = 0;
    while (cnt < n - 1) {
        data = pq.top();
        pq.pop();
        int n1 = data.n1;
        int n2 = data.n2;
        if (find(n1) == find(n2)) continue;
        uni(n1, n2);
        res += data.cost;
        cnt++;
    }
    cout << res << '\n';
    return 0;
}
