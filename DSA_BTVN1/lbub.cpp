#include <iostream>
using namespace std;
struct Node {
    long long key;
    Node *left;
    Node *right;
    Node (long long x) {
        key = x;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node *root;

    Node *insert(Node *root, long long x) {
        if (root == nullptr) {
            root = new Node(x);
            return root;
        }
        if (x < root->key) root->left = insert(root->left, x);
        else root->right = insert(root->right, x);
        return root;
    }

    Node *findLowerbound(Node *root, long long x) {
        if (root == nullptr) return nullptr;
        if (x <= root->key) {
            Node *candidate =findLowerbound(root->left, x);
            return (candidate != nullptr) ? candidate : root;
        }
        else return findLowerbound(root->right, x);
    }

    Node *findUpperbound(Node *root, long long x) {
        if (root == nullptr) return nullptr;
        if (x >= root->key) {
            Node *candidate = findUpperbound(root->right, x);
            return (candidate != nullptr) ? candidate : root;
        }
        else return findUpperbound(root->left, x);
    }

public:
    BST() : root(nullptr) {}

    void insert(long long x) {
        root = insert(root, x);
    }

    long long lowerbound(long long x) {
        Node *lb = findLowerbound(root, x);
        if (lb == nullptr || lb->key >= x) return -1;
        return lb->key;
    }

    long long upperbound(long long x) {
        Node *ub = findUpperbound(root, x);
        if (ub == nullptr || ub->key <= x) return -1;
        return ub->key;
    }
};

int main() {
    BST tree;
    long long a, b;
    while (cin >> a && a != 0) {
        if (a == 1) {
            tree.insert(b);
        }
        else if (a == 2) {
            long long result = tree.lowerbound(b);
            if (result == -1) std::cout << "NULL" << std::endl;
            else std::cout << result << std::endl;
        } else if (a == 3) {
            long long result = tree.upperbound(b);
            if (result == -1) std::cout << "NULL" << std::endl;
            else std::cout << result << std::endl;
        }
    }
    return 0;
}