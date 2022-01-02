#include <iostream>
#include <string>

using namespace std;

int freq[26];
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    string S;
    cin >> S;    
    for (int i = 0; i < S.size(); i++)
        freq[S[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        cout << freq[i] << ' ';
    return 0;
}