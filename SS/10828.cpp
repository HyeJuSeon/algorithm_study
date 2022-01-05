#include <bits/stdc++.h>
using namespace std;

int s[10000];
int curr = -1;
void push(int x) {
    curr++;
    s[curr] = x;
}

int size() {
    return curr + 1;
}

bool empty() {
    if (size() == 0) return true;
    else return false;
}

int pop() {
    if (empty()) return -1;
    else {
        curr--;
        return s[curr + 1];
    }
}

int top() {
    if (empty()) return -1;
    else return s[curr];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            push(x);
        }
        else if (op == "pop") cout << pop() << '\n';
        else if (op == "size") cout << size() << '\n';
        else if (op == "empty") {
            if (empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else cout << top() << '\n';
    }
    return 0;
}