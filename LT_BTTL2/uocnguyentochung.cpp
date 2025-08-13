//
// Created by phamq on 7/31/2025.
//
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int sum_common_prime(int a, int b) {
    int s = 0;
    bool kq = false;
    int minnum = min(a, b);
    for (int i = 2; i <= minnum; i++) {
        if (a % i == 0 && b % i == 0 && isPrime(i)) {
            s += i;
            kq = true;
        }
    }
    return kq ? s : -1;
}

int main() {
    int m, n; cin >> m, n;
    cout << sum_common_prime(m, n);
    return 0;
}