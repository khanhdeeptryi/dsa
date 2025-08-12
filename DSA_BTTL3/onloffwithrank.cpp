#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;
    int size;

    Node(int x): key(x), left(0), right(0), size(1) {}
};

class BinarySearchTree
{
private:
    Node *root;

    int getSize(Node *node)
    {
        return node ? node->size : 0;
    }

    bool _insert(Node *&node, int key)
    {
        if (!node)
        {
            node = new Node(key);
            return true;
        }

        if (node->key == key)
            return false;

        bool inserted = false;
        if (key < node->key)
        {
            inserted = _insert(node->left, key);
        }
        else if (key > node->key)
        {
            inserted = _insert(node->right, key);
        }
        if(inserted)
        {
            node->size = getSize(node->left) + getSize(node->right) + 1;
        }

        return inserted;
    }
    
    void updateSize(Node *node)
    {
        if (node) {
            node->size = getSize(node->left) + getSize(node->right) + 1;
        }
    }

    int _getRank(Node *node, int key) {
        if (!node) {
            return -1;
        }

        if (key < node->key) {
            return _getRank(node->left, key);
        } else if (key > node->key) {
            int right_rank = _getRank(node->right, key);
            if (right_rank != -1) {
                return getSize(node->left) + 1 + right_rank;
            }
            return -1;
        } else {
            return getSize(node->left);
        }
    }

    Node* findMinValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* _erase(Node *node, int key) {
        if (!node) {
            return nullptr; 
        }

        if (key < node->key) {
            node->left = _erase(node->left, key);
        } else if (key > node->key) {
            node->right = _erase(node->right, key);
        } else {
            
            if (!node->left) {
                Node *temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            Node *temp = findMinValueNode(node->right); 
            node->key = temp->key;
            node->right = _erase(node->right, temp->key);   
        }

        updateSize(node);
        return node;
    }

    bool search(Node *node, int key)
    {
        if (!node) return false;
        else if (key < node->key) return search(node->left, key);
        else if (key > node->key) return search(node->right, key);
        return true;
    }
public:
    BinarySearchTree() : root(0) {}

    void insert(int key)
    {
        _insert(root, key);
    }

    void erase(int key)
    {
        root = _erase(root, key);
    }

    int getRank(int key) {
        int rank_zero_based = _getRank(root, key);

        if (rank_zero_based == -1) {
            return 0;
        }
        
        return rank_zero_based + 1;
    }

};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    BinarySearchTree bst;
    int request_type, user_id;

    while (cin >> request_type && request_type != 0)
    {
        cin >> user_id;
        
        if (request_type == 1)
        {
            bst.insert(user_id);
        }
        else if (request_type == 2)
        {
            int rank = bst.getRank(user_id);
            cout << rank << "\n";
        }
        else if (request_type == 3)
        {
            bst.erase(user_id);
        }
    }

    return 0;
}