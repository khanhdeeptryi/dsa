#include <iostream>
using namespace std;

int main() {
    int n, m; cin >> n;
    int *a = new int[n];
    int *b = new int[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int c[n + m];
    int i =0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        }
        else {
            c[k++] = b[j++];
        }
    }
    while (i < n) {
        c[k++] = a[i++];
    }
    while (j < m) {
        c[k++] = b[j++];
    }
    for (int x = 0; x < n + m; x++) {
        cout << c[x];
        if (x < n + m - 1) cout << " ";
    }
    return 0;
}