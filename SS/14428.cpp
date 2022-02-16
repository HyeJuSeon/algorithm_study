#include <iostream>
#define MAXN 300000
#define INF 1000000001
using namespace std;

struct Data {
    int i, n;
    Data() {};
    Data(int i, int n): i(i), n(n) {};

    const bool operator <(const Data other) {
        return n < other.n;
    }

    const bool operator ==(const Data other) {
        return n == other.n;
    }
};

Data IDT[MAXN];
int N, M, S = 1;
void update(int i, int value) {
    i += S - 1;
    IDT[i].n = value;
    while (i > 0) {
        i /= 2;
        if (IDT[i * 2 + 1] < IDT[i * 2]) IDT[i] = Data(IDT[i * 2 + 1].i, IDT[i * 2 + 1].n);
        else IDT[i] = Data(IDT[i * 2].i, IDT[i * 2].n);
    }
}

int getMin(int l, int r) {
    l += S - 1;
    r += S - 1;
    Data res = Data(-1, INF);
    while (l <= r) {
        if (l % 2 == 1) {
            if (IDT[l] < res || (IDT[l] == res && IDT[l].i < res.i)) res = IDT[l];
            l++;
        }
        if (r % 2 == 0) {
            if (IDT[r] < res || (IDT[r] == res && IDT[r].i < res.i)) res = IDT[r];
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return res.i - S + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (S < N) S *= 2;
    fill(IDT, IDT + MAXN, Data(-1, INF));
    int n;
    for (int i = S; i < S + N; i++) {
        cin >> n;
        IDT[i] = Data(i, n);
    }
    for (int i = S - 1; i > 0; i--) {
        if (IDT[i * 2 + 1] < IDT[i * 2]) IDT[i] = Data(IDT[i * 2 + 1].i, IDT[i * 2 + 1].n);
        else IDT[i] = Data(IDT[i * 2].i, IDT[i * 2].n);
    }

    cin >> M;
    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        if (a == 1) update(b, c);
        else cout << getMin(b, c) << '\n';
    }
    return 0;
}