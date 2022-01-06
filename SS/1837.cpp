#include <bits/stdc++.h>
using namespace std;

#define MAXS 102
#define MAXK 1000002

char P[MAXS]; // char 사용한 이유? 10의 100승은 long long으로도 커버가 안돼서
int K;
bool Visit[MAXK];
bool check(int n) {
    int r = 0;
    for (int i = 0; P[i]; i++) r = (r * 10 + (P[i] - '0')) % n;
    return r == 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> P >> K;
    bool good = true;
    int min_prime = 0;
    for (int i = 2; i < K; i++) {
        if (Visit[i]) continue;
        if (check(i)) {
            good = false;
            min_prime = i;
            break;
        }
        for (long long j = (long long)i * i; j < K; j += i) Visit[i] = true;
    }
    if (good) cout << "GOOD";
    else cout << "BAD" << ' ' << min_prime;
    return 0;
}