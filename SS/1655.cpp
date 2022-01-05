#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int> maxheap, minheap;
    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        if (maxheap.size() > minheap.size()) minheap.push(-num);
        else maxheap.push(num);
        if (maxheap.size() && minheap.size() && maxheap.top() > -minheap.top()) {
            int tmp = maxheap.top();
            maxheap.pop();
            maxheap.push(-minheap.top());
            minheap.pop();
            minheap.push(-tmp);
        }
        cout << maxheap.top() << '\n';
    }
    return 0;
}