//
// Created by phamq on 7/27/2025.
//

#include <iostream>
using namespace std;

int input() {
    int a;
    cin >> a;
    return a;
}

void input(int &a) {
    cin >> a;
}

int ucln(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int TongUocChung(int a, int b) {
    int x = ucln(a, b);
    int sum = 0;
    for (int i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            sum += i;
            if (i != x / i) sum += x / i;
        }
    }
    return sum;
}

int main() {
    int a, b;
    a=input();
    input(b);
    std::cout << TongUocChung(a, b);
    return 0;
}
