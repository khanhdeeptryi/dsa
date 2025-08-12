//
// Created by phamq on 7/28/2025.
//
#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

void add(Node* &root, int x) {
    /*
        Hàm thêm một số vào cây
        Hàm này đã được viết đầy đủ và đảm bảo đúng
        Sinh viên không cần phải viết hàm này
    */
    if (root == NULL) {
        root = new Node;
        root->val = x;
        root->left = root->right= NULL;
    } else {
        if (x < root->val) add(root->left, x);
        else if (x > root->val) add(root->right, x);
    }
}

pair <int, int> tmp (Node *root) {
    if (root == nullptr) return {0, 0};
    pair <int, int> left = tmp(root->left);
    pair <int, int> right = tmp(root->right);
    int height = max(left.first, right.first) + 1;
    int unbalance = left.second + right.second;
    if (left.first - right.first >= 2 || right.first - left.first >= 2) unbalance++;
    return {height, unbalance};
}

// int height(Node *root) {
//     if (root == nullptr) return 0;
//     int lHeight = height(root->left);
//     int rHeight = height(root->right);
//     return max(lHeight, rHeight) + 1;
// }

int unbalance(Node *root) {
    return tmp(root).second;
}

int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    Node *root = NULL;

    int x;
    while (cin >> x) {
        add(root, x);
    }

    cout << "So node bi mat can bang la " << unbalance(root);
    return 0;
}
