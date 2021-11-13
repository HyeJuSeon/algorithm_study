#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

vector<string> card_set;
set<string> res;
vector<string> k_set;
int check[11];
int n, k;
void dfs(int depth) {
	if (depth == k) {
		string tmp;
		for (auto k : k_set) tmp += k;
		res.insert(tmp);
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (check[i]) continue;
			check[i] = 1;
			k_set.push_back(card_set[i]);
			dfs(depth + 1);
			check[i] = 0;
			k_set.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		card_set.push_back(num);
	}
	dfs(0);
	cout << res.size() << endl;
	return 0;
}