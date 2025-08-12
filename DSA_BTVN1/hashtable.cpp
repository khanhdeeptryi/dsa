#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct hashtable {
    int size, capacity;
    vector<vector<int>> table;

    int hash(int key) {
        return key % capacity;
    }

    hashtable() {
        size = 1;
        capacity = 1e6 + 3;
        table = vector<vector<int>>(capacity, vector<int>());
    }
    void insert(int k) {
        int vitri = hash(k);
        if (find(table[vitri].begin(),
            table[vitri].end(),
            k) == table[vitri].end()) { //k chua co trong hashtable
            table[vitri].push_back(k);
            size += 1;
            //if (size / capacity > 0.75)
        }
    }

    int count(int k) {
        int vitri = hash(k);
        return find(table[vitri].begin(),
                table[vitri].end(),
                k) != table[vitri].end() ? 1 : 0;
    }

    void erase(int k) {
        int vitri = hash(k);
        auto it = find(table[vitri].begin(), table[vitri].end(), k);
        if (it != table[vitri].end()) {
            table[vitri].erase(it);
            size -= 1;
        }
    }

    void display() {
        cout << "size = " << size << "\n";
        cout << "capacity = " << capacity << "\n";
        for (int i = 0; i < capacity; i++) {
            cout << i << ": ";
            for (auto j : table[i]) cout << j << ", ";
            cout << "\n";
        }
    }

    void enlarge() {
        capacity *= 2;
        auto oldtable = table;
        table = vector<vector<int>>(capacity, vector<int>());
        size = 0;
        for (auto cells: oldtable) {
            for (auto i: cells) {
                insert(i);
            }
        }
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
            cout << cay.count(b) << "\n";
        }
        else if (a == 3) {
            cay.erase(b);
        }
    }
}