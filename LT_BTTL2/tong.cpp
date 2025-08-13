

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double calculate(int n) {
    double s = 0.0;
    for (int i = 1; i <= n; ++i) {
        s = sqrt(i + s);
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    cout << setprecision(3) << calculate(n);
}

