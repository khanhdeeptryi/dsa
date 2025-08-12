
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

int oneChild(Node *root) {
    if (root == nullptr) return 0;
    int result = 0;
    if ((root->left == nullptr && root->right != nullptr) || (root->left != nullptr && root->right == nullptr)) {
        result = 1;
    }
    return result + oneChild(root->left) + oneChild(root->right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Node *root = nullptr;
    int x;
    while(true) {
        cin >> x;
        if (x == 0) break;
        insert(root, x);
    }
    cout << oneChild(root) << endl;

    return 0;
}