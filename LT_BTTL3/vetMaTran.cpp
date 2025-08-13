#include <iostream>
using namespace std;

int main() {
    int m, n; cin >> m >> n;
    double a[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                sum += a[i][j];
            }
        }
    }
    cout << sum;
}