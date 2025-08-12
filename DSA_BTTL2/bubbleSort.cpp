#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[200];
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                // In ra mảng sau mỗi lần swap
                for (int k = 0; k < N; ++k)
                    cout << A[k] << " ";
                cout << endl;
            }
        }
    }
    return 0;
}
