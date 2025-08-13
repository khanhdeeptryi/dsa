//
// Created by phamq on 8/5/2025.
//
#include <iostream>
#include <cmath>
using namespace std;

bool isSNT(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}


void NhapMang(int *a, int &n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void XuatSNT(int *a, int n) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (isSNT(a[i])) {
            cout << a[i] << " ";
            found = true;
        }
    }
    if (!found) cout << 0;
}

int main() {
    int n; cin >> n;
    int *a = new int[n];
    NhapMang(a, n);
    XuatSNT(a, n);
}
