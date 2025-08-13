
#include <iostream>
using namespace std;

int Input() {
    int n;
    cin >> n;
    return n;
}

long long sum_even_divisor(int n) {
    long long sum = 0;
    bool found = false;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i % 2 == 0) {
                sum += i;
                found = true;
            }
            int other = n / i;
            if (other != i && other % 2 == 0) {
                sum += other;
                found = true;
            }
        }
    }
    return found ? sum : -1;
}

int main() {
    int n;
    n=Input();
    cout << sum_even_divisor(n);
}
