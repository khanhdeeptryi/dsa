
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100

void NhapmangSNT(int a[], int &n);
int SoPhanTuChuaY(int a[], int n,int y);

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void NhapmangSNT(int a[], int &n) {
    cin >> n;
    int num = 2;
    int count = 0;
    while (count < n) {
        if (isPrime(num)) {
            a[count] = num;
            count++;
        }
        num++;
    }
}

bool ChuaY(int num, int y) {
    if (num == 0 && y == 0) return true;
    while (num > 0) {
        if (num % 10 == y) return true;
        num /= 10;
    }
    return false;
}

int SoPhanTuChuaY(int a[], int n,int y) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ChuaY(a[i], y)) {
            count++;
        }
    }
    return count;
}

int main()
{
    int a[MAX], n, y;
    cin >>y;
    NhapmangSNT(a,n);
    cout << SoPhanTuChuaY(a, n, y) << endl;;
    return 0;
}