
#include <iostream>
using namespace std;

bool chinhPhuong(int x) {
    for (int i = 1; i <= x / i; ++i) {
        if (i * i == x) return true;
    }
    return false;
}

long long sum_all_square(int n) {
    int sum = 0;
    for (int i = 1; i <= n / i; ++i) {
        if (n % i == 0) {
            if (chinhPhuong(i)) sum += i;
            int j = n / i;
            if (j != i && chinhPhuong(j)) sum += j;
        }
    }
    return sum;
}


int main() {
    int n;
    cin>>n;
    cout << sum_all_square(n);
}
