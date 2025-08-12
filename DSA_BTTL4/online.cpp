//
// Created by phamq on 7/31/2025.
//
#include <iostream>
#include <unodered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_set<int> onlineplayers;
    int x, a; cin >> x;
    while (true) {
        if (x == 0) break;
        cin >> a;
        if (x == 1) onlineplayers.insert(a);
        else if (x == 2) {
            cout << (onlineplayers.count(a) > 0 ? 1 : 0) << "\n";
        }
        else if (x == 3) onlineplayers.erase(a);
    }

    return 0;
}