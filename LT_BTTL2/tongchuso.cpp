//
// Created by phamq on 7/31/2025.
//

#include <iostream>
using namespace std;

void input(int &a) {
    cin >> a;
}

int TongChuSo(int a) {
    int s = 0;
    while (a != 0) {
        s += a % 10;
        a /= 10;
    }
    return s;
}

int main() {
    int a;
    input(a);
    std::cout << TongChuSo(a);
    return 0;
}
