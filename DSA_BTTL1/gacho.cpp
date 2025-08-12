#include <bits/stdc++.h>

using namespace std;

int main() {
    int b, a; // b: tổng số con, a: tổng số chân
    cin >> b >> a;

    int cho = (a - 2 * b) / 2;
    int ga = b - cho;

    cout << ga << " " << cho << endl;

    return 0;
}