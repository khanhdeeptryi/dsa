
#include <iostream>
using namespace std;



struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

struct QNode {
    Node* data;
    QNode* next;
    QNode(Node* d) : data(d), next(nullptr) {}
};

class Queue {
private:
    QNode* front;
    QNode* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}
    ~Queue() {
        while (front != nullptr) {
            QNode* temp = front;
            front = front->next;
            delete temp;
        }
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void enqueue(Node* node) {
        QNode* newNode = new QNode(node);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    Node* dequeue() {
        if (isEmpty()) {
            return nullptr;
        }
        QNode* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        Node* data = temp->data;
        delete temp;
        return data;
    }
};

void insert(Node*& root, int value) {
    Node* current = root;
    Node* parent = nullptr;
    while (current != nullptr) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            return; // Skip duplicates
        }
    }
    Node* newNode = new Node(value);
    if (parent == nullptr) {
        root = newNode;
    } else if (value < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

void levelOrder(Node* root) {
    if (root == nullptr) return;
    Queue q;
    q.enqueue(root);
    q.enqueue(nullptr); // Level separator
    bool firstInLevel = true;
    while (!q.isEmpty()) {
        Node* current = q.dequeue();
        if (current == nullptr) {
            if (!q.isEmpty()) {
                q.enqueue(nullptr);
            }
            cout << endl;
            firstInLevel = true;
        } else {
            if (firstInLevel) {
                cout << current->data;
                firstInLevel = false;
            } else {
                cout << " " << current->data;
            }
            if (current->left != nullptr) {
                q.enqueue(current->left);
            }
            if (current->right != nullptr) {
                q.enqueue(current->right);
            }
        }
    }
}

int main() {
    Node* root = nullptr;
    int num;
    while (cin >> num) {
        if (num == 0) break;
        insert(root, num);
    }
    levelOrder(root);
    return 0;
}