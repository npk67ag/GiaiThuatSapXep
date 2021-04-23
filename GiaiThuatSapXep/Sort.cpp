#include <iostream>
#include<cmath>
#include<ctime>
#include<time.h>
#include <iomanip>
#include<algorithm>
using namespace std;
void Nhap(float[], int);
void Xuat(float[],int);

int main()
{
	int n;
	cin >> n;
	float* a = new float[n];
	Nhap(a, n);

	clock_t s1 = clock();
	sort(a, a + n);
	clock_t e1 = clock();
	cout << "Thoi gian thuc hien: " << 1000 * (double)(e1 - s1) / CLOCKS_PER_SEC << " ms" << endl;
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
	{
		cout << setw(10) << fixed << setprecision(3) << a[i];
	}
}


