#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    if (n <= 0) cout << 0;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max = -1, secondMax = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            secondMax = max;
            max = a[i];
        }
        else if (a[i] > secondMax && a[i] < max) {
            secondMax = a[i];
        }
    }
    if (secondMax == -1) cout << 0;
    else cout << secondMax;
    return 0;
}