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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[j][i];
            if (j < m - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}