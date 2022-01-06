#include <bits/stdc++.h>
using namespace std;

#define MAX 2500000 // 인덱스 트리 크기
#define MAXC 1000000 // 사탕 종류
int Data[MAX];
int leaf = 1;
void update(int B, int C) {
    B += leaf - 1;
    Data[B] += C;
    while (B /= 2) Data[B] += C; 
}

int get_candy(int B) {
    int res = 1;
    while(res < leaf) {
        Data[res]--;
        res *= 2;
        if (B > Data[res]) {
            B -= Data[res];
            res++;
        }
    }
    Data[res]--;
    return res - leaf + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (leaf < MAXC) leaf *= 2;
    for (int i = leaf - 1; i > 0; i--) Data[i] = Data[i * 2] + Data[i * 2 + 1];
    int A, B, C;
    while (n--) {
        cin >> A >> B;
        if (A == 1) cout << get_candy(B) << '\n';
        else {
            cin >> C;
            update(B, C);
        }
    }
    return 0;
}