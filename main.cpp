#include <iostream>
#include <chrono>
#include <cstring>
#include <fstream>
#include "functions.h"

using namespace std;

int main()
{
    ofstream file("Random Timing.txt");

    int dataSize[5] = {10000, 50000, 100000, 300000, 500000};
    string dataOrder[4] = {"Random", "Sorted", "Reverse", "Nearly Sorted"};
    int i = 0;
    file << dataOrder[i] << endl;

    for (int j = 0; j < 5; j++)
    {
        long long compare;
        int n = dataSize[j];
        int *arr = new int[n];
        file << "Data Size: " << n << "\n\n";
        GenerateData(arr, n, i);

        file << "Shell Sort: " << ShellSort_Timing(arr, n) << endl;
        ShellSort_Comparison(arr, n, compare);
        file
            << "Comparisons: " << compare << endl;
        delete[] arr;
        arr = new int[n];
        compare = 0;
        GenerateData(arr, n, i);
        file << "Radix sort: " << RadixSort_Timing(arr, n) << endl;
        RadixSort_Comparison(arr, n, compare);
        file
            << "Comparisons: " << compare << endl;
        delete[] arr;
        arr = new int[n];
        compare = 0;
        GenerateData(arr, n, i);
        file << "Shaker sort: " << ShakerSort_Timing(arr, n) << endl;
        ShakerSort_Compare(arr, n, compare);
        file
            << "Comparisons: " << compare << endl;
        delete[] arr;
        arr = new int[n];
        compare = 0;
        GenerateData(arr, n, i);
        file << "Selection sort: " << SelectionSort_Timing(arr, n) << endl;
        SelectionSort_Compare(arr, n, compare);
        file
            << "Comparisons: " << compare << endl;
        delete[] arr;
        arr = new int[n];
        compare = 0;
        GenerateData(arr, n, i);
        file << "Insertion sort: " << InsertionSort_Timing(arr, n) << endl;
        InsertionSort_Compare(arr, n, compare);
        file
            << "Comparisons: " << compare << endl;
        delete[] arr;
        arr = new int[n];
        compare = 0;
        GenerateData(arr, n, i);
        file << "Heap sort: " << HeapSort_Timing(arr, n) << endl;
        HeapSort_Compare(arr, n, compare);
        file
            << "Comparisons: " << compare << endl;
        delete[] arr;
        arr = new int[n];
        compare = 0;
        GenerateData(arr, n, i);
        file << "Bubble sort: " << BubbleSort_Timing(arr, n) << endl;
        BubbleSort_Compare(arr, n, compare);
        file
            << "Comparisons: " << compare << endl;
        delete[] arr;
        arr = new int[n];
        compare = 0;
        GenerateData(arr, n, i);
        file << "Quick sort: " << QuickSort_Timing(arr, n) << endl;
        QuickSort_Compare(arr, 0, n - 1, compare);
        file
            << "Comparisons: " << compare << endl;
        delete[] arr;
        arr = new int[n];
        compare = 0;
        GenerateData(arr, n, i);
        file << "Merge sort: " << MergeSort_Timing(arr, n) << endl;
        MergeSort_Compare(arr, n, 0, n - 1, compare);
        file
            << "Comparisons: " << compare << endl;
        delete[] arr;
        arr = new int[n];
        compare = 0;
        GenerateData(arr, n, i);
        file << "Couting sort: " << CountingSort_Timing(arr, n) << endl;
        CountingSort_Comparison(arr, n, compare);
        file
            << "Comparisons: " << compare << endl;
        delete[] arr;
        arr = new int[n];
        compare = 0;
        GenerateData(arr, n, i);
        file << "Flash sort: " << FlashSort_Timing(arr, n) << endl;
        FlashSort_Compare(arr, n, compare);
        file
            << "Comparisons: " << compare << endl;
        delete[] arr;

        file << "\n\n";
    }

    /*
    int n = 300000;

    long long compare;
    int *a = new int[n];
    compare = 0;
    GenerateData(a, n, 1);
    MergeSort_Compare(a, n, 0, n - 1, compare);
    cout << compare << endl;
    delete[] a;
    a = new int[n];
    compare = 0;
    GenerateData(a, n, 2);
    MergeSort_Compare(a, n, 0, n - 1, compare);
    cout << compare << endl;
    delete[] a;

    a = new int[n];
    compare = 0;
    GenerateData(a, n, 3);
    MergeSort_Compare(a, n, 0, n - 1, compare);
    cout << compare << endl;
    delete[] a;
*/
    cout << "done";
    return 0;
}