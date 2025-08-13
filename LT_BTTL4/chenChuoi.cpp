//
// Created by phamq on 8/13/2025.
//#include <iostream>
#include <string.h>
using namespace std;

#define MAX 1000

// Hàm chèn chuỗi s1 vào vị trí k của chuỗi s
void insertString(char s[], char s1[], int k) {
    int lenS = strlen(s);
    int lenS1 = strlen(s1);

    // Kiểm tra vị trí k có hợp lệ
    if (k < 0 || k > lenS) {
        cout << "Vi tri " << k << " khong thoa dieu kien." << endl;
        return;
    }

    // Dịch chuyển phần tử từ vị trí k sang phải để tạo chỗ cho s1
    for (int i = lenS; i >= k; i--) {
        s[i + lenS1] = s[i];
    }

    // Chèn s1 vào vị trí k
    for (int i = 0; i < lenS1; i++) {
        s[k + i] = s1[i];
    }

    cout << s << endl;
}

int main() {
    char s[MAX] = {0};
    char s1[MAX] = {0};
    int k;

    // Đọc chuỗi s
    cin.getline(s, MAX);

    // Đọc chuỗi s1
    cin.getline(s1, MAX);

    // Đọc vị trí k
    cin >> k;

    insertString(s, s1, k);

    return 0;
}