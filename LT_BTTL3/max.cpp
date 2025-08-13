//
// Created by phamq on 8/5/2025.
//
#include <iostream>
#include <vector>
using namespace std;

void NhapMang(int *a, int &n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void XuatMang(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int n; cin >> n;
    int *a = new int[n];
    int max = a[0];
    int count = 1;
    NhapMang(a, n);
    //XuatMang(a, n);
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            count = 1;
        }
        else if (a[i] == max) {
            count++;
        }
    }
    cout << max << "\n" << count;
}