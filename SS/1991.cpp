#include <bits/stdc++.h>
using namespace std;

#define MAXN 26

struct Node {
    char left;
    char right;
};

Node Data[MAXN]; 
void preorder(char node) {
    if (node == '.') return;
    cout << node;
    preorder(Data[node].left);
    preorder(Data[node].right);
}

void inorder(char node) {
    if (node == '.') return;
    inorder(Data[node].left);
    cout << node;
    inorder(Data[node].right);
}

void postorder(char node) {
    if (node == '.') return;
    postorder(Data[node].left);
    postorder(Data[node].right);
    cout << node;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        char data, ldata, rdata;
        cin >> data >> ldata >> rdata;
        Data[data].left = ldata;
        Data[data].right = rdata;
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    return 0;
}