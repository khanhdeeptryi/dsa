
// #include <iostream>
// #include <set>
// using namespace std;
//
// int main() {
//     set<pair<int, int>> points;
//     int x, y;
//
//     while (true) {
//         cin >> x;
//         if (x == 0) break; // Kết thúc khi chỉ có 0 trên dòng
//         cin >> y;
//         points.insert({x, y});
//     }
//
//     cout << points.size() << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

struct Node {
    pair<int, int> key;
    Node *left, *right;
    int size;
    Node(pair<int, int> x) {
        key = x;
        left = nullptr;
        right = nullptr;
        size = 1;
    }
};

bool insert(Node *&root, pair<int, int> x) {
    if (root == nullptr) {
        root = new Node(x);
        return true;
    }
    if (root->key == x) return false;
    if (root->key < x) {
        return insert(root->right, x);
    }
    return insert(root->left, x);
}

int demDiemPhanBiet(Node *root) {
    if (root == nullptr) return 0;
    else return 1 + demDiemPhanBiet(root->left) + demDiemPhanBiet(root->right);
}

void deleteTree(Node *root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Node *root = nullptr;
    int x, y, n = 0;
    while (true) {
        cin >> x >> y;
        if (x == 0) break;
        insert(root, {x, y});
    }
    cout << demDiemPhanBiet(root) << endl;
    return 0;
}