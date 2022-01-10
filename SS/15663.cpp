#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define MAXN 8
set< vector<int> > S;
vector<int> v;
int Data[MAXN];
bool Visit[MAXN];
int N, M;
void backtracking(int idx) {
    if (idx == M) {
        S.insert(v);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!Visit[i]) {
            Visit[i] = true;
            v.push_back(Data[i]);
            backtracking(idx + 1);
            Visit[i] = false;
            v.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> Data[i];
    backtracking(0);
    for (auto s : S) {
        for (auto v : s) cout << v << ' ';
        cout << '\n';
    }
    return 0;
}