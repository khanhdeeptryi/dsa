#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Triangle {
    int a, b, c;
    double area;
    int index; // vị trí ban đầu trong mảng
};

// Hàm kiểm tra tam giác hợp lệ
bool is_valid_triangle(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Hàm tính diện tích tam giác theo công thức Heron
double calc_area(int a, int b, int c) {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Thuật toán selection sort giảm dần theo diện tích
void selection_sort(vector<Triangle> &triangles) {
    int n = triangles.size();
    for (int i = 0; i < n - 1; ++i) {
        int max_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (triangles[j].area > triangles[max_idx].area) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            swap(triangles[i], triangles[max_idx]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<tuple<int, int, int>> original(n); // Lưu tam giác gốc
    vector<Triangle> valid_triangles;         // Lưu tam giác hợp lệ + diện tích + chỉ số

    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        original[i] = {a, b, c};

        if (is_valid_triangle(a, b, c)) {
            Triangle t;
            t.a = a;
            t.b = b;
            t.c = c;
            t.area = calc_area(a, b, c);
            t.index = i; // nhớ vị trí để chèn lại
            valid_triangles.push_back(t);
        }
    }

    // Sắp xếp tam giác hợp lệ theo diện tích giảm dần
    selection_sort(valid_triangles);

    // Gán lại tam giác hợp lệ đã sắp xếp vào đúng vị trí trong mảng gốc
    int k = 0;
    for (int i = 0; i < valid_triangles.size(); ++i) {
        int idx = valid_triangles[i].index;
        original[idx] = {valid_triangles[i].a, valid_triangles[i].b, valid_triangles[i].c};
    }

    // In kết quả
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        tie(a, b, c) = original[i];
        cout << a << " " << b << " " << c << "\n";
    }

    return 0;
}
