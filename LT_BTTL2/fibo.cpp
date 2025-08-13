//
// Created by phamq on 7/31/2025.
//

#include <iostream>
using namespace std;
#define MAX 300

int Fibo(int);

int main()
{
    int x;
    cin >> x;
    if (x < 1 || x>30)
        cout << "So " << x << " khong nam trong khoang [1,30]." << endl;
    else
    {
        cout << Fibo(x) << endl;
    }
    return 0;
}

int Fibo(int n) {
    if (n <= 2) return 1;
    int f1 = 1, f2 = 1, fn;
    for (int i = 3; i <= n; i++) {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return fn;
}