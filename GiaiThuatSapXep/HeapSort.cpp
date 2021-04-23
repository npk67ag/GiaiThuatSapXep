#include <iostream>
#include<cmath>
#include<ctime>
#include<time.h>
#include <iomanip>
using namespace std;
void Nhap(float[], int);
void Xuat(float[], int);
void heapify(float[], int, int);
void heapSort(float[], int);

int main()
{
	int n;
	cin >> n;
	float* arr = new float[n];
	Nhap(arr, n);

	clock_t s1 = clock();
	heapSort(arr, n);
	clock_t e1 = clock();
	cout << "Thoi gian thuc hien: " << 1000 * (double)(e1 - s1) / CLOCKS_PER_SEC << " ms" << endl;

}

void Nhap(float arr[], int n)
{
	srand(std::time(nullptr));
	for (int i = 0; i < n; i++)
	{
		arr[i] = -100.0 + rand() / (RAND_MAX / (100.0 - (-100.0)));
	}
}

void Xuat(float arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << fixed << setprecision(3) << arr[i];
	}
}

void heapify(float arr[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);

		heapify(arr, n, largest);
	}
}

void heapSort(float arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {

		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

