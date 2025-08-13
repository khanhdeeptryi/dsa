#include <iostream>
#include <string.h>
using namespace std;

#define MAX 1000

// Hàm đảo ngược chuỗi từ vị trí start đến end-1
void reverseWord(char s[], int start, int end) {
    int i = start, j = end - 1;
    while (i < j) {
        // Swap ký tự
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

// Hàm đảo ngược các từ trong chuỗi
void reverseWords(char s[]) {
    int length = strlen(s);
    
    // Nếu chuỗi rỗng hoặc chỉ có khoảng trắng
    bool isEmpty = true;
    for (int i = 0; i < length; i++) {
        if (s[i] != ' ' && s[i] != '\n' && s[i] != '\r') {
            isEmpty = false;
            break;
        }
    }
    
    if (isEmpty) {
        cout << "Chuoi rong." << endl;
        return;
    }
    
    int start = 0;
    for (int i = 0; i <= length; i++) {
        // Khi gặp khoảng trắng hoặc kết thúc chuỗi, đảo ngược từ
        if (i == length || s[i] == ' ') {
            if (start < i) {  // Đảm bảo từ không rỗng
                reverseWord(s, start, i);
            }
            start = i + 1;  // Cập nhật vị trí bắt đầu của từ tiếp theo
        }
    }
    
    cout << s << endl;
}

int main() {
    char s[MAX];
    
    // Đọc chuỗi vào từ input
    cin.getline(s, MAX);
    
    reverseWords(s);
    
    return 0;
}