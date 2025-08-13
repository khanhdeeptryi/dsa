//
// Created by phamq on 7/31/2025.
//

#include <iostream>
using namespace std;
int reverse(int n) {
    int result = 0;
    while (n > 0) {
        result = result * 10 + n % 10;
        n /= 10;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << reverse(n);
}
