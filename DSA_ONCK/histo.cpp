#include <iostream>
using namespace std;

struct Node {
    long long key;
    int f;
    Node *left, *right;

    Node (long long x) {
        key = x;
        left = right = nullptr;
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
        if (x < root->key) root->left = insert(root->left, x);
        else if (x > root->key) root->right = insert(root->right, x);
        else root->f++;
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
    BST tree;
    long long x;
    while (cin >> x && x != 0) {
        tree.insert(x);
    }
    tree.RNL(tree.root);
    return 0;
}