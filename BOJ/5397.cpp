#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string pw;
        list<char> L;
        cin >> pw;
        auto cursor = L.end();
        for (auto ch : pw) {
            if (ch == '-') {
                if (cursor != L.begin()) {
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else if (ch == '<') {
                if (cursor != L.begin()) cursor--;
            }
            else if (ch == '>') {
                if (cursor != L.end()) cursor++;
            }
            else {
                L.insert(cursor, ch);
            }
        }
        for (auto ch : L) cout << ch;
        cout << '\n';
    }
    return 0;
}