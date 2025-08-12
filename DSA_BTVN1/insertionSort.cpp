#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// Sinh một hoán vị có đúng target_swap lần dòng 6 chạy (insertion)
vector<int> generatePermutation(vector<int> A, int target_swap) {
    int n = A.size();
    sort(A.begin(), A.end());
    vector<int> result;

    for (int i = n - 1; i >= 0; --i) {
        if (target_swap >= i) {
            result.insert(result.begin(), A[i]);
            target_swap -= i;
        } else {
            result.insert(result.begin() + (result.size() - target_swap), A[i]);
            target_swap = 0;
        }
    }

    if (target_swap != 0) return {};
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        int n = stoi(line); // dòng đầu tiên của test
        getline(cin, line); // dòng thứ 2 chứa mảng + k
        istringstream iss(line);

        vector<int> raw;
        int value;
        while (iss >> value) raw.push_back(value);

        if (raw.size() < n + 1) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        vector<int> A(raw.begin(), raw.begin() + n);
        int k = raw.back();

        int max_swap = n * (n - 1) / 2;
        if (k > max_swap || k < 0) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        vector<int> result = generatePermutation(A, k);
        if (result.empty()) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (int i = 0; i < result.size(); ++i) {
                cout << result[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
