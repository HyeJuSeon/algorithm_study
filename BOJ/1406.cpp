#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    list<char> L;
    int m;
    str = "abcde";
    cin >> str;
    for (auto ch : str) L.push_back(ch);
    cin >> m;
    auto cursor = L.end();
    for (int i = 0; i < m; i++) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L' && cursor != L.begin()) {
            cursor--;
        }
        else if (cmd == 'D' && cursor != L.end()) {
            cursor++;
        }
        else if (cmd == 'B' && cursor != L.begin()) {
            cursor--;
            cursor = L.erase(cursor);
        }
        else if (cmd == 'P') {
            char ch;
            cin >> ch;
            L.insert(cursor, ch);
        }
    }
    for (auto ch : L) cout << ch;
    return 0;
}