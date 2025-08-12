#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int m; cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // for (int i = 0; i < m; i++) {
    //     int less = 0, greater = 0;
    //     for (int j = 0; j < n; j++) {
    //         if (a[j] < b[i]) {
    //             less++;
    //         }
    //         else if (a[j] > b[i]) {
    //             greater++;
    //         }
    //     }
    //     cout << less << " " << greater << endl;
    // }

    for (int i = 0; i < m; i++) {
        int less = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        int greater = a.end() - upper_bound(a.begin(), a.end(), b[i]);
        cout << less << " " << greater << "\n";
    }

    return 0;
}