#include <iostream>
#include <chrono>
#include "functions.h"

using namespace std;

int main()
{
    int dataSize[5] = {10000, 50000, 100000, 300000, 500000};
    int compare = 0;

    cout << "Time: " << MergeSort_Timing(a, n);
    for (int i = 0; i < 5; i++)
    {
        n = a[i];
        int *arr = new int[n];

        GenerateData(arr, n, 0);

        ShellSort_Timing(arr, n);
        RadixSort_Timing(arr, n);
        ShakerSort_Timing(arr, n);
        SelectionSort_Timing(arr, n);
        InsertionSort_Timing(arr, n);
        HeapSort_Timing(arr, n);
        BubbleSort_Timing(arr, n);
        QuickSort_Timing(arr, n);
        MergeSort_Timing(arr, n);
        CountingSort_Timing(arr, n);
        FlashSort_Timing(arr, n);
    }
    return 0;
}