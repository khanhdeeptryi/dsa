#include <iostream>

using namespace std;

struct Node {
    long long key;
    int f;
    Node *left;
    Node *right;
    Node (long long x) {
        key = x;
        left = nullptr;
        right = nullptr;
        f = 1;
    }
};

class BST {
public:
    Node *root;
    BST() {
        root = nullptr;
    }
    void insert(long long x) {
        root = insert(root, x);
    }
    Node *insert(Node *root, long long x) {
        if (root == nullptr) {
            root = new Node(x);
            return root;
        }
        if (x < root->key) {
            root->left = insert(root->left, x);
        }
        else if (x > root->key) {
            root->right = insert(root->right, x);
        }
        else {
            root->f++;
        }
        return root;
    }
    void RNL(Node *root) {
        if (root != nullptr) {
            RNL(root->right);
            cout << root->key << " " << root->f << "\n";
            RNL(root->left);
        }
    }
};


int main() {
    BST bst;
    while (true) {
        long long x; cin >> x;
        if (x == 0) break;
        bst.insert(x);
    }
    bst.RNL(bst.root);
    return 0;
}

// #include <iostream>
// #include <map>
//
// int main() {
//     // Sử dụng map với bộ so sánh std::greater để sắp xếp giảm dần
//     std::map<long long, int, std::greater<long long>> frequencyMap;
//     long long num;
//
//     // Đọc input cho đến khi gặp số 0
//     while (std::cin >> num) {
//         if (num == 0) {
//             break;
//         }
//         frequencyMap[num]++; // Tăng tần suất của số num
//     }
//
//     // Xuất bảng tần suất
//     for (const auto& pair : frequencyMap) {
//         std::cout << pair.first << " " << pair.second << std::endl;
//     }
//
//     return 0;
// }