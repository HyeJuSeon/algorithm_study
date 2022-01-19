#include <iostream>
#define MAXC 1000000
using namespace std;

int IDT[MAXC * 3];
int N, Start = 1;
void update(int i, int num) {
    i += Start - 1;
    while (i > 0) {
        IDT[i] += num;
        i /= 2;
    }
}

int get(int num) {
    int i = 1;
    while (i < Start) {
        i *= 2;
        if (num > IDT[i]) {
            num -= IDT[i];
            i++;
        }
        IDT[i]--;
    }
    return i - Start + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (Start < MAXC) Start *= 2;
    int a, b, c;
    while (N--) {
        cin >> a >> b;
        if (a == 1) cout << get(b) << '\n';
        else {
            cin >> c;
            update(b, c);
        }
    }
    return 0;
}
