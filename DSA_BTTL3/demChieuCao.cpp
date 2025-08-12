//
// Created by phamq on 7/21/2025.
//
#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    Node (int x) {
        key = x;
        left = nullptr;
        right = nullptr;
    }
};

void insert(Node *&root, int x) {
    if (root == nullptr) {
        root = new Node(x);
        return;
    }
    if (x < root->key) return insert(root->left, x);
    if (x > root->key) return insert(root->right, x);
}

int height(Node *root) {
    if (root == nullptr) return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    return max(lHeight, rHeight) + 1;
}

int main() {
    Node *root = nullptr;
    int x;
    while (true) {
        cin >> x;
        if (x == 0) break;
        insert(root, x);
    }
    cout << height(root) << endl;

    return 0;
}