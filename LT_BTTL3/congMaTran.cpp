#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n; cin >> m >> n;
    vector<vector<float>> a(m, vector<float>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int l, k; cin >> l >> k;
    vector<vector<float>> b(m, vector<float>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    vector<vector<float>> c(m, vector<float>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}