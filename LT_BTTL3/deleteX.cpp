#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x; cin >> x;
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != x) {
            a[m++] = a[i];
        }
    }
    for (int i = 0; i < m; i++) {
        cout << a[i];
        if (i < m - 1) cout << " ";
    }

    return 0;
}