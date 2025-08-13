#include <iostream>
using namespace std;

int main() {
    int m, n; cin >> m >> n;
    double a[m][n];

    if (m != n) cout << "No";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    bool mtdc = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != j && a[i][j] != 0) {
                mtdc = false;
            }
        }
    }
    cout << (mtdc ? "Yes" : "No");
}