#include <iostream>
#include <string>

using namespace std;

int freq[10];
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    int a, b, c;
    string str;
    cin >> a >> b >> c;
    str = to_string(a * b * c);
    for (int i = 0; i < str.size(); i++)
        freq[str[i] - '0']++;
    for (int i = 0; i < 10; i++)
        cout << freq[i] << '\n';
    return 0;
}