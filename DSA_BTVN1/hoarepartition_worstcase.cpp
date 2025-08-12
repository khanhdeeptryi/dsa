#include <algorithm>
#include <compare>
#include <concepts>
#include <functional>
#include <bits/stdc++.h>

using namespace std;

int partition(int pivot, int *a, int n) {
    int count = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        while (a[left] < pivot){
            left++;
            count++;
        }
        while (a[right] > pivot){
            right--;
            count++;
        }
        count += 2;

        if (left <= right)
        {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    return left-1;
}



void quicksort(int *a, int l, int r){
    if (r > l){
        auto pivot = a[(l+r)/2];
        auto i = partition(pivot, a+l, r-l+1);
        quicksort(a, l, l+i);
        quicksort(a, l+i+1, r);
    }
}

int main() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}