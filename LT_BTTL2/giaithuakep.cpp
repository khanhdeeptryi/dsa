//
// Created by phamq on 7/31/2025.
//
#include <iostream>
using namespace std;

long long giaithuakep(int n) {
    long long result = 1;
    for (int i = n; i >= 1; i -= 2) {
        result *= i;
    }
    return result;
}

int main() {
    int n; cin >> n;
    cout << giaithuakep(n);
    return 0;
}