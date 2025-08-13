#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void DemTieng(char s1[]);
int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void myMemmove(char s[], int vt, int k);
int myStrstr(char s[], char s1[]);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);

// Tính chiều dài chuỗi bắt đầu từ vị trí k
int myStrlen(char s[], int k) {
    if (!s) return 0;
    int i = k;
    while (s[i] != '\0') i++;
    return i - k;
}

// So sánh hai chuỗi
int myStrcmp(char s1[], char s2[]) {
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

// Sao chép chuỗi s1 bắt đầu từ vị trí k vào chuỗi s tại vị trí vt
void myStrcpy(char s[], int vt, char s1[], int k) {
    int i = 0;
    while (s1[k + i] != '\0') {
        s[vt + i] = s1[k + i];
        i++;
    }
    s[vt + i] = '\0';
}

// Di chuyển vùng nhớ trong chuỗi s từ vị trí k+vt đến k
void myMemmove(char s[], int vt, int k) {
    int len = myStrlen(s, 0);
    if (vt > k) {
        // Di chuyển từ phải sang trái
        for (int i = k; i <= len; i++) {
            s[i] = s[i + vt - k];
        }
    } else if (vt < k) {
        // Di chuyển từ trái sang phải
        for (int i = len; i >= k; i--) {
            s[i + vt - k] = s[i];
        }
    }
}

// Tìm vị trí xuất hiện đầu tiên của chuỗi s1 trong chuỗi s
int myStrstr(char s[], char s1[]) {
    int lenS = myStrlen(s, 0);
    int lenS1 = myStrlen(s1, 0);
    
    for (int i = 0; i <= lenS - lenS1; i++) {
        int j;
        for (j = 0; j < lenS1; j++) {
            if (s[i + j] != s1[j]) break;
        }
        if (j == lenS1) return i;
    }
    
    return -1;
}

// Trích xuất chuỗi con từ chuỗi s bắt đầu từ vị trí b với độ dài count
void mySubstr(char s[], int b, int count, char ss[]) {
    int i;
    for (i = 0; i < count && s[b + i] != '\0'; i++) {
        ss[i] = s[b + i];
    }
    ss[i] = '\0';
}

// Nối chuỗi s2 vào sau chuỗi s1
bool myStrcat(char s1[], char s2[]) {
    int len1 = myStrlen(s1, 0);
    int len2 = myStrlen(s2, 0);
    
    // Kiểm tra xem có đủ bộ nhớ không
    if (len1 + len2 >= MAX) return false;
    
    // Nối s2 vào sau s1
    for (int i = 0; i <= len2; i++) {
        s1[len1 + i] = s2[i];
    }
    
    return true;
}

// Hàm kiểm tra ký tự có phải là khoảng trắng
bool isSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Hàm đếm số lần xuất hiện của từng từ trong chuỗi
void DemTieng(char s1[]) {
    // Loại bỏ ký tự newline ở cuối
    int len = myStrlen(s1, 0);
    while (len > 0 && (s1[len-1] == '\n' || s1[len-1] == '\r')) {
        s1[--len] = '\0';
    }
    
    // Mảng lưu trữ các từ riêng biệt
    char words[MAX][MAX] = {0};
    int counts[MAX] = {0};
    int wordCount = 0;
    
    // Xử lý từng từ trong chuỗi
    int i = 0;
    while (i < len) {
        // Bỏ qua khoảng trắng
        while (i < len && isSpace(s1[i])) i++;
        if (i >= len) break;
        
        // Lấy một từ
        char currentWord[MAX] = {0};
        int wordPos = 0;
        while (i < len && !isSpace(s1[i])) {
            currentWord[wordPos++] = s1[i++];
        }
        currentWord[wordPos] = '\0';
        
        // Kiểm tra từ này đã xuất hiện chưa
        bool found = false;
        for (int j = 0; j < wordCount; j++) {
            if (myStrcmp(words[j], currentWord) == 0) {
                counts[j]++;
                found = true;
                break;
            }
        }
        
        // Nếu từ chưa xuất hiện, thêm vào danh sách
        if (!found) {
            myStrcpy(words[wordCount], 0, currentWord, 0);
            counts[wordCount] = 1;
            wordCount++;
        }
    }
    
    // In kết quả
    for (int i = 0; i < wordCount; i++) {
        cout << words[i] << ": " << counts[i] << endl;
    }
}

int main()
{
    char s[MAX];
    fgets(s, MAX, stdin);
    if (myStrcmp(s, "\n") == 0 || myStrcmp(s, "") == 0 || myStrlen(s, 0) == 0) {
        cout << "Chuoi rong." << endl;
    } else {
        DemTieng(s);
    }
    return 0;
}