
#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

#define fast_io     ios_base::sync_with_stdio(false)

struct Node {
    char key[101];
    Node *left;
    Node *right;
    Node (char x[]) {
        int i = 0;
        while (x[i] != '\0') {
            key[i] = x[i];
            i++;
        }
        key[i] = '\0';
        left = 0;
        right = 0;
    }
};

int compare (char *a, char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0' ) {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
        i++;
    }
    if (a[i] == '\0' && b[i] != '\0') return -1;
    if (a[i] == '\0') return -1;
    return 1;
}

void insert(Node *&root, char *x) {
    if (root == nullptr) {
        root = new Node(x);
        return;
    }
    int cmp = compare(x, root->key);
    if (cmp < 0) insert(root->left, x);
    else if (cmp > 0) insert(root->right, x);
}

int search(Node *root, char *x) {
    if (root == nullptr) return 0;
    int cmp = compare(x, root->key);
    if (cmp == 0) return 1;
    else if (cmp < 0) return search(root->left, x);
    else return search(root->right, x);
}

void readline (int &x, char *b) {
    char c;
    x = 0;
    int i = 0;
    int reading = 1;
    while (1) {
        c = getchar();
        if (c == '\n' || c == -1) break;
        if (c == ' ') {
            reading = 0;
            continue;
        }
        if (reading) {
            x = x * 10 + (c - '0');
        }
        else b[i++] = c;
    }
    b[i] = '\0';
}

void printInt (int x) {
    if (x == 0) {
        putchar('0');
        putchar('\n');
        return;
    }
    char buf[10];
    int i = 0;
    while (x > 0) {
        buf[i++] = '0' + (x % 10);
        x /= 10;
    }
    for (int j = i - 1; j >= 0; j--) {
        putchar(buf[j]);
    }
    putchar('\n');
}

int main() {
    Node* root = 0; // Khởi tạo cây rỗng
    int x;
    char B[101]; // Mảng ký tự lưu chuỗi B
    while (cin >> x && x != 0) {
        readline(x, B);
        if (x == 1) {
            insert(root, B); // Thêm từ khóa
        } else if (x == 2) {
            int result = search(root, B); // Kiểm tra từ khóa
            printInt(result);
        }
    }
    return 0;
}