#include <iostream>
#include <limits>
using namespace std;

bool check(unsigned long long day, unsigned long long a, unsigned long long k, unsigned long long b, unsigned long long m, unsigned long long n) {
    unsigned long long work_days1 = day - day / k;
    unsigned long long work_days2 = day - day / m;

    const unsigned long long MAX_ULL = std::numeric_limits<unsigned long long>::max();

    if (a > 0 && work_days1 > 0 && a > MAX_ULL / work_days1) return true;

    unsigned long long cut1 = work_days1 * a;

    if (cut1 >= n) return true;

    unsigned long long remaining_n = n - cut1;

    if (b > 0 && work_days2 > 0 && b > MAX_ULL / work_days2) return true;

    unsigned long long cut2 = work_days2 * b;

    return cut2 >= remaining_n;
}

int main() {
    unsigned long long a, k, b, m, n;

    cin >> a >> k >> b >> m >> n;

    unsigned long long low = 1;
    unsigned long long high = 1e19;
    unsigned long long final_day = high;

    while (low <= high) {
        unsigned long long mid = low + (high - low) / 2;

        if (check(mid, a, k, b, m, n)) {
            final_day = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << final_day;

    return 0;
}