//
// Created by phamq on 8/5/2025.
//
#include <iostream>
using namespace std;
void NhapMang(int *a, int &n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void XuatLe(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {
            cout << a[i] << " ";
        }
    }
}

int main() {
    int n; cin >> n;
    int *a = new int[n];
    NhapMang(a, n);
    XuatLe(a, n);
}