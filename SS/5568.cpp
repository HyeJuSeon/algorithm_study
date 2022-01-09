#include <iostream>
#include <string>
#include <set>
using namespace std;

#define MAXN 10
int Card[MAXN];
bool Visit[MAXN];
set<string> NumSet;
int N, K;
void backtracking(int idx, string str) {
	if (idx == K) {
		NumSet.insert(str);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!Visit[i]) {
			Visit[i] = true;
			backtracking(idx + 1, str + to_string(Card[i]));
			Visit[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> Card[i];
	backtracking(0, "");
	cout << (int)NumSet.size() << '\n';
	return 0;
}