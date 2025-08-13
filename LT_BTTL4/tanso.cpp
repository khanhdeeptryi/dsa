#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void DemKyTu(char s[]);
int myStrcmp(char s1[MAX], char s2[MAX]);
int myStrlen(char s[], int k);

// Tính chiều dài chuỗi bắt đầu từ vị trí k
int myStrlen(char s[], int k) {
    if (!s) return 0;
    int i = k;
    while (s[i] != '\0') i++;
    return i - k;
}

// So sánh hai chuỗi
int myStrcmp(char s1[MAX], char s2[MAX]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') return 0;
    if (s1[i] == '\0') return -1;
    return 1;
}

// Hàm đếm số lần xuất hiện của từng ký tự trong chuỗi
void DemKyTu(char s[]) {
    int len = myStrlen(s, 0);
    
    // Loại bỏ ký tự newline ở cuối nếu có
    if (len > 0 && (s[len-1] == '\n' || s[len-1] == '\r')) {
        s[--len] = '\0';
    }
    
    // Mảng đánh dấu ký tự đã được đếm chưa
    bool counted[256] = {false};
    
    // Duyệt qua từng ký tự trong chuỗi
    for (int i = 0; i < len; i++) {
        // Nếu ký tự chưa được đếm
        if (!counted[(unsigned char)s[i]]) {
            counted[(unsigned char)s[i]] = true;
            
            // Đếm số lần xuất hiện của ký tự này
            int count = 0;
            for (int j = 0; j < len; j++) {
                if (s[j] == s[i]) {
                    count++;
                }
            }
            
            // In kết quả
            cout << s[i] << ": " << count << endl;
        }
    }
}

int main()
{
    char s[MAX];
    fgets(s, MAX, stdin);    //Nhap chuoi s
    
    // Kiểm tra chuỗi rỗng
    if (myStrlen(s, 0) <= 1 && s[0] == '\n') {
        cout << "Chuoi rong." << endl;
    } else {
        DemKyTu(s);
    }

    return 0;
}
