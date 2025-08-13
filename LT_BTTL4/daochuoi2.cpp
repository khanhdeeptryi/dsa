#include <iostream>
#include <string.h>
using namespace std;

#define MAX 1000

// Kiểm tra ký tự có phải là khoảng trắng
bool isSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Hàm đảo ngược thứ tự các từ trong chuỗi
void reverseWordsOrder(char s[]) {
    int length = strlen(s);
    
    // Kiểm tra chuỗi rỗng
    bool isEmpty = true;
    for (int i = 0; i < length; i++) {
        if (!isSpace(s[i])) {
            isEmpty = false;
            break;
        }
    }
    
    if (isEmpty) {
        cout << "Chuoi rong." << endl;
        return;
    }
    
    // Mảng để lưu kết quả
    char result[MAX] = {0};
    int resultIndex = 0;
    
    // Duyệt chuỗi từ cuối lên đầu để tìm từng từ
    int end = length;
    
    while (end > 0) {
        // Bỏ qua khoảng trắng ở cuối
        while (end > 0 && isSpace(s[end-1])) {
            end--;
        }
        
        if (end <= 0) break;
        
        // Tìm vị trí bắt đầu của từ
        int start = end - 1;
        while (start > 0 && !isSpace(s[start-1])) {
            start--;
        }
        
        // Sao chép từ vào kết quả
        for (int i = start; i < end; i++) {
            result[resultIndex++] = s[i];
        }
        
        // Thêm khoảng trắng sau từ (ngoại trừ từ đầu tiên)
        if (start > 0) {
            result[resultIndex++] = ' ';
        }
        
        end = start;
    }
    
    result[resultIndex] = '\0'; // Kết thúc chuỗi kết quả
    cout << result << endl;
}

int main() {
    char s[MAX];
    
    // Đọc chuỗi vào từ input
    cin.getline(s, MAX);
    
    reverseWordsOrder(s);
    
    return 0;
}