#include <bits/stdc++.h>
using namespace std;

priority_queue<int> Data;
int get_mid() {
    priority_queue<int> pq;   
    int len = Data.size(); 
    for (int i = 0; i < len / 2; i++) {
        pq.push(Data.top());
        Data.pop();
    }
    int res = Data.top();
    while (!pq.empty()) {
        Data.push(pq.top());
        pq.pop();
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        Data.push(num);
        if (Data.size() < 2) {
            cout << Data.top() << '\n';
            continue;
        }
        cout << get_mid() << '\n';
    }
    return 0;
}