#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

int q[MAXN];
int head = 0;
int tail = -1;
int size() {
    return tail - head + 1;  
}

bool empty() {
    if (size() == 0) return true;
    else return false;
}

void push(int x) {
    tail++;
    q[tail] = x;
}

int pop() {
    if (empty()) return -1;
    else {
        head++;
        return q[head - 1];
    }
}

int front() {
    if (empty()) return -1;
    else return q[head];
}

int back() {
    if (empty()) return -1;
    else return q[tail];
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
        else if (op == "front") cout << front() << '\n';
        else cout << back() << '\n';
    }
    return 0;
}