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
    bool mtdx = true;
    for (int i = 0; i < n && mtdx; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                mtdx = false;
                break;
            }
        }
    }
    cout << (mtdx ? "Yes" : "No");
}