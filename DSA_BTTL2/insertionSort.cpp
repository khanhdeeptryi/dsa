#include <bits/stdc++.h>
using namespace std;

// Nguồn tham khảo: https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/

void printArray(vector<int> a, int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

void insertionSort(vector<int>& a, int n)
{
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
            printArray(a, n); 
        }
        a[j + 1] = key;
        printArray(a, n);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    insertionSort(a, n);    
    return 0;
}