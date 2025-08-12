#include <iostream>
#include <vector>

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

Node *buildTree (vector<int> & a, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    Node *node = new Node(a[mid]);
    node->left = buildTree(a, start, mid - 1);
    node->right = buildTree(a, mid + 1, end);
    return node;
}

void LRN(Node *root) {
    if (root == nullptr) return;
    LRN(root->left);
    LRN(root->right);
    cout << root->key << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v;
    int x;
    while (cin >> x) {
        v.push_back(x);
    }
    Node *root = buildTree(v, 0, v.size() - 1);
    LRN(root);
    return 0;
}
