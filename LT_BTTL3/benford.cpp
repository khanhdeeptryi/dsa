//
// Created by phamq on 8/5/2025.
//

#include <iostream>
using namespace std;
#define MAX 100

void Nhapmang(int *a, int &n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

bool isBenford(int *a, int n) {
    int count1 = 0; // Count numbers starting with 1
    int count4 = 0; // Count numbers starting with 4

    for (int i = 0; i < n; i++) {
        int num = a[i];
        // Get the first digit by continuously dividing by 10
        while (num >= 10) {
            num /= 10;
        }

        // Check if first digit is 1 or 4
        if (num == 1) {
            count1++;
        } else if (num == 4) {
            count4++;
        }
    }

    // Return true if there are exactly 3 numbers starting with 1
    // and exactly 1 number starting with 4
    return (count1 == 3 && count4 == 1);
}


int main()
{
    int a[MAX], n = 10;
    Nhapmang(a, n);
    if (isBenford(a, n) == true)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
    return 0;
}
