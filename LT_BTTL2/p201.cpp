//
// Created by phamq on 7/24/2025.
//
#include <iostream>
using namespace std;

int main() {
    int age; cin >> age;
    char gender; cin >> gender;
    if (gender == 'M' || gender == 'm') {
        if (age >= 21) cout << 1;
        if (age < 21) cout << 3;
    }
    else if (gender == 'F' || gender == 'f') {
        if (age >= 21) cout << 2;
        if (age < 21) cout << 4;
    }
    else cout << "I do not know why";

    return 0;
}