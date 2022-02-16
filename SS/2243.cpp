#include <iostream>
#define MAXN 3000000
#define MAXC 1000000
using namespace std;

int IDT[MAXN];
int N, S = 1;
void update(int i, int value) {
    i += S - 1;
    while (i > 0) {
        IDT[i] += value;
        i /= 2;
    }
}

int out(int rank) {
    int i = 1;
    IDT[i]--;
    while (i < S) {
        i *= 2;
        if (rank > IDT[i]) {
            rank -= IDT[i];
            i++;
        }
        IDT[i]--;
    }
    return i - S + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (S < MAXC) S *= 2;
    cin >> N;
    int a, b, c;
    while (N--) {
        cin >> a >> b;
        if (a == 1) cout << out(b) << '\n';
        else {
            cin >> c;
            update(b, c);
        }
    }
    return 0;
}
