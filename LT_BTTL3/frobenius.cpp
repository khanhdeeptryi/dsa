#include <iostream>
#include <vector>
using namespace std;

bool isFrobeniusMatrix(const vector<vector<double>>& A, int n) {
    int specialColumn = -1; // lưu chỉ số cột đặc biệt (nếu có)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                // Đường chéo chính phải bằng 1
                if (A[i][j] != 1) return false;
            }
            else if (i < j) {
                // Trên đường chéo chính: phải bằng 0
                if (A[i][j] != 0) return false;
            }
            else if (i > j) {
                // Dưới đường chéo chính
                if (A[i][j] != 0) {
                    if (specialColumn == -1) {
                        specialColumn = j; // ghi nhận cột đặc biệt
                    } else if (specialColumn != j) {
                        return false; // xuất hiện giá trị khác 0 ở cột khác => sai
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int r, c;
    cin >> r >> c;
    if (r != c) { // ma trận Frobenius phải là ma trận vuông
        cout << "No";
        return 0;
    }

    vector<vector<double>> A(r, vector<double>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> A[i][j];
        }
    }

    cout << (isFrobeniusMatrix(A, r) ? "Yes" : "No");
    return 0;
}