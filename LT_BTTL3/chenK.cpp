//
// Created by phamq on 8/5/2025.
//
#include <iostream>
#include <vector>
using namespace std;

// void NhapMang(int *a, int &n) {
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
// }
//
// void chenK(int *a, int &n, int x, int k) {
//     cin >> x >> k;
//     for (int i = n; i > k; i--) {
//         a[i] = a[i - 1];
//     }
//     a[k] = x;
//     n++;
//     for (int i = 0; i < n; i++) {
//         cout << a[i] << " ";
//     }
// }
//
// // void XuatMang(int *a, int n) {
// //
// // }

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x, k; cin >> x >> k;
    for (int i = n; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;
    n++;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}