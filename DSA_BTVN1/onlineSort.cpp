#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//1. Them vao mang (da online dung them vao nua, them xong sort cai mang lai, nen dung online.insert (upperbound())
bool isOnline(const vector<int> &online, int x) {
    return binary_search(online.begin(), online.end(), x);
}

void addPlayer(vector<int> &online, int x) {
    if (!isOnline(online, x)) {
        online.insert(upper_bound(online.begin(), online.end(), x), x);
    }
}

// void insertionSort(vector<int> &online) {
//     int n = online.size();
//     for (int i = 1; i < n; i++) {
//         int key = online[i];
//         int j = i - 1;
//         while (j >= 0 && online[j] > key) {
//             online[j + 1] = online[j];
//             j--;
//         }
//         online[j + 1] = key;
//     }
// }

int findPosition(const vector<int> &online, int x) {
    auto it = lower_bound(online.begin(), online.end(), x);
    if (it == online.end() || *it != x) return 0;
    return it - online.begin() + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> online;

    while (true) {
        int a; cin >> a;
        if (a == 0) break;

        int b; cin >> b;
        if (a == 1) addPlayer(online, b);
        else if (a == 2) cout << findPosition(online, b) << "\n";
    }

    return 0;
}

