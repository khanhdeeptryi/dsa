//
// Created by phamq on 8/6/2025.
//
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int hashf (int k, int i, int m, int a, int b) {
    return ((k % m + m) % m + a * i + b * i * i) % m;
}

void hashTable (int m, int a, int b, vector<int> &elm) {
    vector<string> table(m, "None");
    for (int key : elm) {
        bool inserted = false;
        for (int i = 0; i < m; i++) {
            int index = hashf(key, i, m, a, b);
            if (table[index] == "None") {
                table[index] = to_string(key);
                inserted = true;
                break;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << table[i];
        if (i != m - 1) cout << ", ";
    }
    cout << "\n";
}

int main() {
    string line;
    while (getline(cin, line) && line != "0") {
        stringstream ss(line);
        int m, a, b;
        ss >> m >> a >> b;

        getline(cin, line);
        stringstream ss2(line);
        vector<int> elm;
        int num;
        while (ss2 >> num) {
            elm.push_back(num);
        }
        hashTable(m, a, b, elm);
    }
    return 0;
}