#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b; cin >> a >> b;
    if (a == 0) {
        if (b == 0) cout <<"ℝ";
        else cout <<"Ø";
    }
    else if (a != 0) {
        double x = -(b / a);
        cout << "{" << x <<"}";
    }

    return 0;
}
