#include <iostream>
#include <iomanip>
#include<cmath>
#include <ctime>
#include <time.h>
#include<stdlib.h>
using namespace std;

void Nhap(float[], int);
int SoSanh(const void*, const void*);
void Xuat(float[], int);

int main()
{
	int n;
	cin >> n;
	float* a = new float[n];
	Nhap(a, n);

	clock_t s1, e1;

	s1 = clock();
	qsort(a, n, sizeof(float), SoSanh);
	e1 = clock();
	cout << "Thoi gian thuc hien: " << 1000 * (double)(e1 - s1) / CLOCKS_PER_SEC << endl;

	return 0;
}

void Nhap(float a[], int n)
{
	srand(std::time(nullptr));
	for (int i = 0; i < n; i++)
	{
		a[i] = -100.0 + rand() / (RAND_MAX / (100.0 - (-100.0)));
	}
}

void Xuat(float a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(10) << fixed << setprecision(3) << a[i];
}

int SoSanh(const void* a, const void* b)
{
	const float* x = (float*)a;
	const float* y = (float*)b;
	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}