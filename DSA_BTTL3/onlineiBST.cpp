//
// Created by phamq on 7/23/2025.
//
#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int size;
    Node(int x) {
        key = x;
        left = nullptr;
        right = nullptr;
        size = 1;
    }
};

bool insert(Node *&root, int x) {
    if (root == nullptr) {
        root = new Node(x);
        return true;
    }
    else {
        if (root->key == x) return false;
        bool kq_insert = false;
        if (x < root->key) kq_insert = insert(root->left, x);
        if (root->key < x) kq_insert = insert(root->right, x);
        if (kq_insert) root->size++;

        return kq_insert;
    }
}

int rankSearch(Node *root, int x) {
    if (root == nullptr) return 0;
    if (root->key == x) {
        int leftSize = root->left ? root->left->size : 0;
        return leftSize + 1;
    }
    else if (x < root->key) return rankSearch(root->left, x);
    else {
        int leftSize = root->left ? root->left->size : 0;
        int rightRank = rankSearch(root->right, x);
        if (rightRank == 0) return 0;
        return leftSize + 1 + rightRank;
    }
}

bool remove(Node *&root, int x) {
    if (root == nullptr) return false;
    if (root->key == x) {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = 0;
        }
        auto temp = root;
        if (root->left != nullptr && root->right == nullptr) {
            root = root->left;
            delete temp;
        }
        if (root->left == nullptr && root->right != nullptr) {
            root = root->right;
            delete temp;
        }
        // if (root->left != nullptr && root->right != nullptr)
        else {
            Node *y = root->left;
            while (y->right) y = y->right;
            root->key = y->key;
            root->size--;
            remove(root->left, y->key);
        }
        return true;
    }
    bool kq_remove = false;
    if (root->key < x) {
        kq_remove = remove(root->right, x);
    }
    else kq_remove = remove(root->left, x);
    if (kq_remove) root->size--;
    return kq_remove;
}

// void dumpTree(Node *root) {
//     if (root == nullptr) return;
//     dumpTree(root->left);
//     cout << "[" << root->key << ", " << root->size << "]" << ", " << root->left <<", " << root->right << "\n";
//     dumpTree(root->right);
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Node *root = nullptr;
    int x, id;
    while (true) {
        cin >> x;
        if (x == 0) break;
        cin >> id;
        if (x == 1) {
            insert(root, id);
        }
        else if (x == 2) {
            int pos = rankSearch(root, id);

            cout << pos <<"\n";
        }
        else if (x == 3) {
            remove(root, id);
        }
    }
}