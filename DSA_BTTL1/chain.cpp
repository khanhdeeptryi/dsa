#include <bits/stdc++.h>

using namespace std;

/*
int main() {
    long long d, r, n; cin >> d >> r >> n;
    int L = (n - 2) * (2 * r - 2 * d) + 4 * r;
    cout << L;

    return 0;
}
*/

long long result(long long d, long long r, long long n) {
    return 2 * d + 2 * n * r;
}

int main() {
    long long d, r, n; cin >> d >> r >> n;
    cout << result(d, r, n);
}