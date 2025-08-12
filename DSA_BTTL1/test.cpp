#include <iostream>
#include <ctime>
#define MIN -2000
#define MAX 2000
using namespace std;

int getInteger(string s) {
	int n;
	do {
		cout << "Please choose a number in a range 1 to 100.000.000: ";
		cin >> n;
		if (n < 0 || n > 100000000 || n == 0) {
			cout << "Nhap lai: ";
		}
	} while (n < 0 || n > 100000000 || n == 0);
	return n;
}

void generateArray(int a[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = MIN + rand() % (MAX - MIN + 1);
	}
}

void outputArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void Menu() {
	cout << " __________________________ " << endl;
	cout << "| ********* MENU ********* |" << endl;
	cout << "| 1.Selection Sort         |" << endl;
	cout << "| 2.Interchange Sort       |" << endl;
	cout << "| 3.Insertion Sort         |" << endl;
	cout << "| 4.BinaryInsertion Sort   |" << endl;
	cout << "| 5.Bubble Sort            |" << endl;
	cout << "| 6.Shake Sort             |" << endl;
	cout << "| 7.Counting Sort          |" << endl;
	cout << "| 8.Quick Sort             |" << endl;
	cout << "| 9.Merge Sort             |" << endl;
	cout << "| 10.Heap Sort             |" << endl;
	cout << "| 11.Shell Sort            |" << endl;
	cout << "| 12.Radix Sort            |" << endl;
	cout << "| 13.Quit                  |" << endl;
	cout << "|__________________________|" << endl;
	cout << endl;
}

void SelectionSort(int a[], int n) {
	int i, j, min;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}

void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}

void InsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (x < a[j])
				a[j + 1] = a[j];
			else
				break;
		}
		a[j + 1] = x;
	}
}

int binarySearch(int a[], int item,
	int low, int high)
{
	if (high <= low)
		return (item > a[low]) ?
		(low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item,
			mid + 1, high);
	return binarySearch(a, item, low,
		mid - 1);
}


void BinaryInsertionSort(int a[], int n)
{
	int i, loc, j, k, selected;

	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = a[i];


		loc = binarySearch(a, selected, 0, j);


		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

void BubbleSort(int a[], int n) {
	bool swapped;
	for (int i = 0; i < n; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

void ShakeSort(int a[], int n) {
	int l = 0;
	int r = n - 1;
	int k = 0;
	while (l < r) {
		for (int i = l; i < r; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		r = k;
		for (int i = r; i > l; i--) {
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		l = k;
	}
}

void CountingSort(int a[], int n) {
	int* b = new int[n];
	int max = a[0];
	int min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		else if (a[i] < min)
			min = a[i];
	}
	int k = max - min + 1;
	int* count_array = new int[k];
	fill_n(count_array, k, 0);
	for (int i = 0; i < n; i++)
		count_array[a[i] - min]++;
	for (int i = 1; i < k; i++)
		count_array[i] += count_array[i - 1];
	for (int i = 0; i < n; i++)
	{
		b[count_array[a[i] - min] - 1] = a[i];
		count_array[a[i] - min]--;
	}
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}

void quicksort(int a[], int l, int r) {
	int i = l, j = r;
	int x = a[(l + r) / 2];
	int dem = 0;
	while (i <= j) {
		while (a[i] < x) {
			i++;
		}
		while (a[j] > x) {
			j--;
		}
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (l < j)
		quicksort(a, l, j);
	if (i < r)
		quicksort(a, i, r);
}

void Merge(int a[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];

	int i = 0, j = 0; int k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k++] = L[i];
			i++;
		}
		else
		{
			a[k++] = R[j];
			j++;
		}

	}
	while (i < n1)
	{
		a[k++] = L[i++];
	}
	while (j < n2)
	{
		a[k++] = R[j++];
	}
}

void MergeSort(int a[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		Merge(a, l, m, r);
	}
}

void heapify(int a[], int N, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < N && a[l] > a[largest])
		largest = l;
	if (r < N && a[r] > a[largest])
		largest = r;
	if (largest != i) {
		swap(a[i], a[largest]);
		heapify(a, N, largest);
	}
}

void HeapSort(int a[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(a, N, i);
	for (int i = N - 1; i > 0; i--) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

int ShellSort(int a[], int n) {
	for (int k = n / 2; k > 0; k /= 2) {
		for (int i = k; i < n; i++) {
			int temp = a[i];
			int j;
			for (j = i; j >= k && a[j - k] > temp; j -= k) {
				a[j] = a[j - k];
			}
			a[j] = temp;
		}
	}
	return 0;
}

int getMax(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}


void countSort(int a[], int n, int exp) {
	int* output = new int[n];
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++) {
		count[(a[i] / exp) % 10]++;
	}


	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}


	for (i = n - 1; i >= 0; i--) {
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++) {
		a[i] = output[i];
	}
}


void RadixSort(int arr[], int n) {
	int m = getMax(arr, n);


	for (int exp = 1; m / exp > 0; exp *= 10) {
		countSort(arr, n, exp);
	}
}
void radixSort(int a[], int n) {
	int cD = 0, cA = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) cA++;
		else cD++;
	}
	int* b = new int[cD];
	int* c = new int[cA];
	int icD = 0, icA = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) c[icA++] = a[i];
		else b[icD++] = a[i];
	}
	RadixSort(b, cD);
	RadixSort(c, cA);
	for (int i = 0; i < n; i++) {
		if (i < cA) a[i] = c[i];
		else a[i] = b[i - cA];
	}
}


int main()
{
	int n = getInteger("Please choose a number in a range 1 to 100.000.000");
	int* a = new int[n];
	generateArray(a, n);
	outputArray(a, n);
	char c;
	do
	{
		Menu();
		cout << "Please choose an algorithm: ";
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			clock_t start = clock();
			SelectionSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time:" << (double)(finish - start) / CLOCKS_PER_SEC << " s" << endl;
			break;
		}
		case 2:
		{
			clock_t start = clock();
			InterchangeSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time:" << (double)(finish - start) / CLOCKS_PER_SEC << " s" << endl;
			break;
		}
		case 3:
		{
			clock_t start = clock();
			InsertionSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time:" << (double)(finish - start) / CLOCKS_PER_SEC << " s" << endl;
			break;
		}
		case 4:
		{
			clock_t start = clock();
			BinaryInsertionSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time:" << (double)(finish - start) / CLOCKS_PER_SEC << " s" << endl;
			break;
		}
		case 5:
		{
			clock_t start = clock();
			BubbleSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time:" << (double)(finish - start) / CLOCKS_PER_SEC << " s" << endl;
			break;
		}
		case 6:
		{
			clock_t start = clock();
			ShakeSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time:" << (double)(finish - start) / CLOCKS_PER_SEC << " s" << endl;
			break;
		}
		case 7:
		{
			clock_t start = clock();
			CountingSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time:" << (double)(finish - start) / CLOCKS_PER_SEC << " s" << endl;
			break;
		}
		case 8:
		{
			clock_t start = clock();
			quicksort(a, 0, n - 1);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time:" << (double)(finish - start) / CLOCKS_PER_SEC << " s" << endl;
			break;
		}
		case 9:
		{
			clock_t start = clock();
			MergeSort(a, 0, n - 1);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time:" << (double)(finish - start) / CLOCKS_PER_SEC << " s" << endl;
			break;
		}
		case 10:
		{
			clock_t start = clock();
			HeapSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time:" << (double)(finish - start) / CLOCKS_PER_SEC << " s" << endl;
			break;
		}
		case 11:
		{
			clock_t start = clock();
			ShellSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time:" << (double)(finish - start) / CLOCKS_PER_SEC << " s" << endl;
			break;
		}
		case 12:
		{
			clock_t start = clock();
			radixSort(a, n);
			clock_t finish = clock();
			cout << "Sorted Array: ";
			outputArray(a, n);
			cout << "Time:" << (double)(finish - start) / CLOCKS_PER_SEC << " s" << endl;
			break;
		}
		case 13:
		{
			break;
		}
		default:
		{
			cout << "Nhap sai!" << endl;
			break;
		}
		}
		if (choose == 13)
		{
			break;
		}
		cout << "Do you want to continue? ";
		cin >> c;
		if (c != 'Y' && c != 'y')
		{
			if (c == 'N' || c == 'n')
			{
				cout << "See you again!";
			}
			else
			{
				cout << "Nhap sai roi fen oi?" << endl;
			}
		}
	} while (c == 'Y' || c == 'y');
	return 0;
}
