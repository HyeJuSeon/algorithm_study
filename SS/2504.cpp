#include <iostream>
#include <stack>
#include <string>
using namespace std;

string Input;
stack<char> S;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> Input;
    int res = 0, tmp = 1;
    for (int i = 0; i < Input.length(); i++) {
        if (Input[i] == '(') {
            S.push('(');
            tmp *= 2;
        }
        else if (Input[i] == '[') {
            S.push('[');
            tmp *= 3;
        }
        else if (Input[i] == ')') {
            if (S.empty() || S.top() != '(') {
                res = 0;
                break;
            }
            if (S.top() == '(') {
                if (Input[i - 1] == '(') res += tmp;
                tmp /= 2;
                S.pop();
            }        
        }
        else if (Input[i] == ']') {
            if (S.empty() || S.top() != '[') {
                res = 0;
                break;
            }
            if (S.top() == '[') {
                if (Input[i - 1] == '[') res += tmp;
                tmp /= 3;
                S.pop();
            }
        }
    }
    if (S.empty()) cout << res << '\n';
    else cout << 0 << '\n';
    return 0;
}