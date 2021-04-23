#include <iostream>
#include <ctime>
#include <time.h>
#include <iomanip>
using namespace std;

void Nhap(float[], int);
void Xuat(float[], int);
int partition(float[], int, int);
void quickSort(float[], int, int);

int main()
{
    int n;
    cin >> n;
    float* arr = new float[n];
    Nhap(arr, n);
    quickSort(arr, 0, n - 1);

    clock_t s1, e1;

    s1 = clock();
    quickSort(arr, 0, n - 1);
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
    {
        cout << setw(10) << fixed << setprecision(3) << a[i];
    }
}

void swap(float* a, float* b)
{
    float t = *a;
    *a = *b;
    *b = t;
}

int partition(float arr[], int low, int high)
{
    float pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(float arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


