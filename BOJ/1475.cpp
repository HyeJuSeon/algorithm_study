#include <iostream> 
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    int freq[10] = {};
    int n;
    cin >> n;
    while (n > 0) {
        freq[n % 10]++;
        n /= 10;
    }    
    int max_elem = max(*max_element(freq, freq + 6), max(freq[7], freq[8]));
    cout << max(max_elem, (freq[6] + freq[9] + 1) / 2) << '\n';
    return 0;   
}