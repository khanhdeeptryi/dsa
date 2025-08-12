#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *prev;
    Node *next;
    Node *next_in_bucket;

    Node(int x) {
        key = x;
        prev = nullptr;
        next = nullptr;
        next_in_bucket = nullptr;
    }
};

struct hashtable {
    int size, capacity;
    vector<Node*> table;
    Node *head, *tail;

    int hash(int key) {
        return (long long)key % capacity;
    }

    hashtable() {
        size  = 0;
        capacity = 1e6 + 3;
        table.resize(capacity, nullptr);
        head = tail = nullptr;
    }

    Node *findNode(int k) {
        int vitri = hash(k);
        Node *current = table[vitri];
        while (current != nullptr) {
            if (current->key == k) return current;
            current = current->next_in_bucket;
        }
        return nullptr;
    }

    void insert(int k) {
        if (findNode(k)) return;
        Node * newNode = new Node(k);
        int vitri = hash(k);
        newNode->next_in_bucket = table[vitri];
        table[vitri] = newNode;

        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size += 1;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    hashtable cay;
    int a, b;
    while (cin >> a && a != 0) {
        cin >> b;
        if (a == 1) {
            cay.insert(b);
        }
        else if (a == 2) {
            Node *foundNode = cay.findNode(b);
            if (!foundNode) cout << "N\n";
            else {
                cout << foundNode->key;
                int count = 0;
                Node *current = foundNode;
                while (count < 2 && current->prev != nullptr) {
                    current = current->prev;
                    cout << " " << current->key;
                    count += 1;
                }
                cout << "\n";
            }
        }
    }
}