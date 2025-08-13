
#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int maxDayinmonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

int main() {
    int d, m, y; cin >> d >> m >> y;
    if ( y <= 0) {
        cout << "Nam khong hop le.";
    }
    else if (m < 1 || m > 12) {
        cout << "Thang khong hop le.";
    }
    else {
        if (d >= 1 && d <= maxDayinmonth(m, y)) {
            cout << d << "/" << m << "/" << y << " la ngay hop le.";
        }
        else {
            cout << d << "/" << m << "/" << y << " la ngay khong hop le.";
        }
    }

    return 0;
}