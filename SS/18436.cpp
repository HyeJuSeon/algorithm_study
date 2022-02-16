#include <iostream>
#define MAXN 300000
using namespace std;

struct Data {
    int e, o;
    Data() {};
    Data(int e, int o): e(e), o(o) {};
};

int N, M, S = 1;
Data IDT[MAXN];
void update(int i, int value) {
    i += S - 1;
    bool isEven = (value % 2 == 0) ? true : false;
    bool prevIsEven = (IDT[i].e) ? true : false;
    while (i > 0) {
        if (prevIsEven && !isEven) {
            IDT[i].e--;
            IDT[i].o++;
        }
        else if (!prevIsEven && isEven) {
            IDT[i].e++;
            IDT[i].o--;
        }
        else break;
        i /= 2;
    }
}

int numEven(int l, int r) {
    l += S - 1;
    r += S - 1;
    int res = 0;
    while (l <= r) {
        if (l % 2 == 1) res += IDT[l++].e;
        if (r % 2 == 0) res += IDT[r--].e;
        l /= 2;
        r /= 2;
    }
    return res;
}

int numOdd(int l, int r) {
    l += S - 1;
    r += S - 1;
    int res = 0;
    while (l <= r) {
        if (l % 2 == 1) res += IDT[l++].o;
        if (r % 2 == 0) res += IDT[r--].o;
        l /= 2;
        r /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (S < N) S *= 2;
    int num;
    for (int i = S; i < S + N; i++) {
        cin >> num;
        if (num % 2 == 0) IDT[i] = Data(1, 0);
        else IDT[i] = Data(0, 1);
    }
    for (int i = S - 1; i > 0; i--) IDT[i] = Data(IDT[i * 2].e + IDT[i * 2 + 1].e, IDT[i * 2].o + IDT[i * 2 + 1].o);

    cin >> M;
    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        if (a == 1) update(b, c);
        else if (a == 2) cout << numEven(b, c) << '\n';
        else cout << numOdd(b, c) << '\n';
    }
    return 0;
}