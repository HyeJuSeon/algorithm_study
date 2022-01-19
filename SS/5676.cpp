#include <iostream>
#define MAXN 100000
using namespace std;

int IDT[MAXN * 3];
int N, K, Start = 1;
void update(int i, int value) {
    i += Start - 1;
    bool preZero = false;
    if (!IDT[i]) preZero = true;
    int m;
    if (IDT[i] * value > 0) return;
    else if (IDT[i] * value < 0) m = -1;
    else m = 0;
    IDT[i] = value;
    while (i > 0) {
        i /= 2;
        if (preZero) {
            if (IDT[i * 2] * IDT[i * 2 + 1] > 0) IDT[i] = 1;
            else if (IDT[i * 2] * IDT[i * 2 + 1] < 0) IDT[i] = -1;
            else IDT[i] = 0;
        } 
        else IDT[i] *= m;
    }
}

void mul(int l, int r) {
    l += Start - 1;
    r += Start - 1;
    int res = 1;
    while (l <= r) {
        if (l % 2 == 1) res *= IDT[l++];
        if (r % 2 == 0) res *= IDT[r--];
        l /= 2;
        r /= 2;
    }
    if (res < 0) cout << '-';
    else if (res > 0) cout << '+';
    else cout << 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char op;
    int i, j;
    while (cin >> N >> K) {
        while (Start < N) Start *= 2;
        fill(IDT, IDT + MAXN * 3, 1);
        for (int i = Start; i < Start + N; i++) cin >> IDT[i];
        for (int i = Start - 1; i > 0; i--) {
            if (IDT[i * 2] * IDT[i * 2 + 1] < 0) IDT[i] = -1;
            else if (IDT[i * 2] * IDT[i * 2 + 1] > 0) IDT[i] = 1;
            else IDT[i] = 0;
        }
        while (K--) {
            cin >> op >> i >> j;
            if (op == 'C') update(i, j);
            else mul(i, j);
        }
        cout << '\n';
    }
    return 0;
}