
#include <iostream>
using namespace std;
#define MAX 16

void Nhapmang(int a[][MAX], int &n);
void Xuatmang(int a[][MAX], int n);

void Nhapmang(int a[][MAX], int &n) {
    cin >> n;
    if (n < 2 || n > MAX) return;
    int fib[2 * MAX];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 2 * MAX; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = fib[i + j + 1];
        }
    }
}

void Xuatmang(int a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n, a[MAX][MAX];
    Nhapmang(a,n);
    Xuatmang(a,n);

    return 0;
}


// int main() {
//     int n; cin >> n;
//     if (n < 2 || n > 16) return 0;
//     int fib[40];
//     fib[0] = 0;
//     fib[1] = 1;
//     for (int i = 2; i < 40; i++) {
//         fib[i] = fib[i - 1] + fib[i - 2];
//     }
//
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cout << fib[i + j + 1];
//             if (j < n - 1) cout << " ";
//         }
//         cout << "\n";
//     }
//
//     return 0;
// }