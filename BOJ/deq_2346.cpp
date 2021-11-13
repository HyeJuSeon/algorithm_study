#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	deque<pair<int, int>> circle;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		circle.push_back(make_pair(i, num));
	}

	cout << circle.front().first << ' ';
	int next = circle.front().second;
	circle.pop_front();
	while (!circle.empty()) {
		if (next > 0) {
			while (--next) {
				circle.push_back(circle.front());
				circle.pop_front();
			}
			cout << circle.front().first << ' ';
			next = circle.front().second;
			circle.pop_front();
		}
		else {
			while (++next) {
				circle.push_front(circle.back());
				circle.pop_back();
			}
			cout << circle.back().first << ' ';
			next = circle.back().second;
			circle.pop_back();
		}
	}
	return 0;
}
