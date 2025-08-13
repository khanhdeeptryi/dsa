
#include <iostream>
using namespace std;

void input(int &n) {
    cin >> n;
}

int input() {
    int n;
    cin >> n;
    return n;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int m, n;
    input(n);
    m = input();
    cout << gcd(m, n);
}
