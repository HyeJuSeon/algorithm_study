#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string str;
	cin >> str;
	int m;
	cin >> m;
	stack<char> s1;
	stack<char> s2;

	for (char ch : str)
		s1.push(ch);
	
	while (m--) {
		char cmd;
		cin >> cmd;
		char top;
		if (cmd == 'L') {
			if (!s1.empty()) {
				top = s1.top();
				s1.pop();
				s2.push(top);
			}
		}
		else if (cmd == 'D') {
			if (!s2.empty()) {
				top = s2.top();
				s2.pop();
				s1.push(top);
			}
		}
		else if (cmd == 'B') {
			if (!s1.empty())
				s1.pop();
		}
		else {
			char elem;
			cin >> elem;
			s1.push(elem);
		}
	}
	
	stack<char> tmp;
	while(!s1.empty()) {
		tmp.push(s1.top());
		s1.pop();
	}

	while (!tmp.empty()) {
		cout << tmp.top();
		tmp.pop();
	}
	while (!s2.empty()) {
		cout << s2.top();
		s2.pop();
	}
	return 0;
}