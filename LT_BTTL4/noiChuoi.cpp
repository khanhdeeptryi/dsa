#include <iostream>
#include <string.h>
using namespace std;

#define MAX_LEN 255 // Chiều dài tối đa 254 ký tự + 1 ký tự null terminator

// Hàm nối chuỗi s2 vào cuối chuỗi s1
// Trả về true nếu nối thành công, false nếu không đủ bộ nhớ
bool concatStrings(char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Kiểm tra xem có đủ bộ nhớ để nối không
    if (len1 + len2 >= MAX_LEN) {
        return false;
    }
    
    // Nối s2 vào cuối s1
    strcat(s1, s2);
    return true;
}

int main() {
    char s1[MAX_LEN] = {0};
    char s2[MAX_LEN] = {0};
    
    // Đọc chuỗi s1
    cin.getline(s1, MAX_LEN);
    
    // Đọc chuỗi s2
    cin.getline(s2, MAX_LEN);
    
    // Nối chuỗi và xuất kết quả
    if (concatStrings(s1, s2)) {
        cout << s1 << endl;
    } else {
        cout << "Khong noi duoc. Khong du bo nho." << endl;
    }
    
    return 0;
}