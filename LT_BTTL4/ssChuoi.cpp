#include <iostream>
#include <string.h>
using namespace std;

#define MAX_LEN 255 // Chiều dài tối đa 254 ký tự + 1 ký tự null terminator

// Hàm so sánh hai chuỗi
// Trả về:
// -1 nếu s1 < s2
// 0 nếu s1 = s2
// 1 nếu s1 > s2
int compareStrings(const char* s1, const char* s2) {
    int result = strcmp(s1, s2);
    
    if (result < 0) {
        return -1;
    } else if (result > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char s1[MAX_LEN];
    char s2[MAX_LEN];
    
    // Đọc chuỗi s1
    cin.getline(s1, MAX_LEN);
    
    // Đọc chuỗi s2
    cin.getline(s2, MAX_LEN);
    
    // So sánh và xuất kết quả
    int result = compareStrings(s1, s2);
    cout << result << endl;
    
    return 0;
}