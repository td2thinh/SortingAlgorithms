#include <iostream>
#include <chrono>

using namespace std;

void RadixSort(int arr[], int n)
{

    int *b = new int[n];
    int m = arr[0], exp = 1;

    for (int i = 0; i < n; i++)
        if (arr[i] > m)
            m = arr[i];

    while (m / exp > 0)
    {
        int count[10] = {0};
        for (int i = 0; i < n; i++)
            count[arr[i] / exp % 10]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--)
            b[--count[arr[i] / exp % 10]] = arr[i];
        for (int i = 0; i < n; i++)
            arr[i] = b[i];
        exp *= 10;
    }
    delete[] b;
}

void RadixSort_Comparison(int arr[], int n, int &compare)
{
    compare = 0;

    int *b = new int[n];
    int m = arr[0], exp = 1;

    for (int i = 0; ++compare, i < n; i++)
        if (++compare, arr[i] > m)
            m = arr[i];

    while (++compare && m / exp > 0)
    {
        int count[10] = {0};
        for (int i = 0; ++compare, i < n; i++)
            count[arr[i] / exp % 10]++;
        for (int i = 1; ++compare, i < 10; i++)
            count[i] += count[i - 1];
        for (int i = n - 1; ++compare, i >= 0; i--)
            b[--count[arr[i] / exp % 10]] = arr[i];
        for (int i = 0; ++compare, i < n; i++)
            arr[i] = b[i];
        exp *= 10;
    }
    delete[] b;
}

double RadixSort_Timing(int arr[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    RadixSort(arr, n);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, milli> elapsed = finish - start;
    return elapsed.count();
}
