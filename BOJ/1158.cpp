#include <iostream>
#include <list>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    list<int> L;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) L.push_back(i);
    cout << '<';
    while (L.size() != 1) {
        for (int i = 0; i < k - 1; i++) {
            L.push_back(L.front());
            L.pop_front();
        }
        cout << L.front() << ", ";
        L.pop_front();
    }
    cout << L.front() << '>' << '\n';
    return 0;
}