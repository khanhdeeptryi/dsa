#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int p, k;
    cin >> p >> k;

    // Xóa k phần tử từ vị trí p
    for (int i = p + k; i < n; i++) {
        arr[i - k] = arr[i];
    }
    n -= k;

    // In mảng mới
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }

    return 0;
}
