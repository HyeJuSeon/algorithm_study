#include <iostream>
using namespace std;

#define MAXN 200000
#define MAXH 500000
int N, H, MinHuddle, MinCnt;
int Cnt[MAXH];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> H;
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        if (i % 2 == 0) {
            Cnt[0]++;
            Cnt[b]--;
        }
        else Cnt[H - b]++;
    }
    int tmp_cnt = 0;
    MinHuddle = MAXN + 1;
    for (int i = 0; i < H; i++) {
        tmp_cnt += Cnt[i];
        if (tmp_cnt < MinHuddle) {
            MinHuddle = tmp_cnt;
            MinCnt = 1;
        }
        else if (tmp_cnt == MinHuddle) MinCnt++;
    }
    cout << MinHuddle << ' ' << MinCnt << '\n';
    return 0;
}