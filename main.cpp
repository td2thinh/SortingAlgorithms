#include <iostream>
#include <chrono>
#include <cstring>
#include <fstream>
#include "functions.h"

using namespace std;

int main()
{
    //ofstream file("Radix Timing.txt");

    int dataSize[5] = {10000, 50000, 100000, 300000, 500000};
    string dataOrder[4] = {"Random", "Sorted", "Reverse", "Nearly Sorted"};

    /*    for (int i = 0; i < 4; i++)
    {
        file << dataOrder[i] << endl;

        for (int j = 0; j < 5; j++)
        {
            long long compare = 0;
            int n = dataSize[j];
            int *arr = new int[n];
            file << "Data Size: " << n << "\n\n";
            GenerateData(arr, n, i);

            //file << "Shell Sort: " << ShellSort_Timing(arr, n) << endl;
            //ShellSort_Comparison(arr, n, compare);

            file << "Radix Short: " << RadixSort_Timing(arr, n) << endl;
            RadixSort_Comparison(arr, n, compare);
            //file << "Shaker Short: " << ShakerSort_Timing(arr, n) << endl;
            //file << "Selection Short: " << SelectionSort_Timing(arr, n) << endl;
            //file << "Insertion Short: " << InsertionSort_Timing(arr, n) << endl;
            //file << "Heap Short: " << HeapSort_Timing(arr, n) << endl;
            //HeapSort_Compare(arr, n, compare);
            //file << "Bubble Short: " << BubbleSort_Timing(arr, n) << endl;
            //file << "Quick Short: " << QuickSort_Timing(arr, n) << endl;
            //QuickSort_Compare(arr, 0, n - 1, compare);
            //file << "Merge Short: " << MergeSort_Timing(arr, n) << endl;
            //MergeSort_Compare(arr, n, 0, n - 1, compare);
            //file << "Couting Short: " << CountingSort_Timing(arr, n) << endl;
            //CountingSort_Comparison(arr, n, compare);

            //file << "Flash Short: " << FlashSort_Timing(arr, n) << endl;
            //FlashSort_Compare(arr, n, compare);
            file
                << "Comparisons: " << compare << endl;

            delete[] arr;
        }

        file << "\n\n";
    }
    */
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

    cout << "done";
    return 0;
}