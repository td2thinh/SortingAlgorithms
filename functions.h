#include <iostream>
#include <cstring>
#include <fstream>
#include <time.h>
#include <cmath>
#include <chrono>
#include <sstream>
using namespace std;

void GenerateData(int a[], int n, int dataType);

int ShellSort(int arr[], int n);
double ShellSort_Timing(int arr[], int n);
void ShellSort_Comparison(int arr[], int n, int &compare);
void RadixSort(int arr[], int n);
double RadixSort_Timing(int arr[], int n);
void RadixSort_Comparison(int arr[], int n, int &compare);
void ShakerSort(int a[], int n);
double ShakerSort_Timing(int a[], int n);
void ShakerSort_Compare(int a[], int n, int &count_compare);
void SelectionSort(int a[], int n);
double SelectionSort_Timing(int a[], int n);
void SelectionSort_Compare(int a[], int n, int &count_compare);
void InsertionSort(int a[], int n);
double InsertionSort_Timing(int a[], int n);
void InsertionSort_Compare(int a[], int n, int &count_compare);
void HeapSort(int a[], int n);
double HeapSort_Timing(int a[], int n);
void HeapSort_Compare(int a[], int n, int &count_compare);
void BubbleSort(int a[], int n);
double BubbleSort_Timing(int a[], int n);
void BubbleSort_Compare(int a[], int n, int &count_compare);
void QuickSort(int a[], int first, int last);
double QuickSort_Timing(int a[], int n);
void QuickSort_Compare(int a[], int first, int last, int &compare);
void MergeSort(int theArray[], int n, int first, int last);
double MergeSort_Timing(int a[], int n);
void MergeSort_Compare(int theArray[], int n, int first, int last, int &compare);
void CountingSort(int a[], int n);
double CountingSort_Timing(int arr[], int n);
void CountingSort_Comparison(int a[], int n, int &compare);
void FlashSort(int a[], int n);
double FlashSort_Timing(int arr[], int n);
void FlashSort_Compare(int a[], int n, int &compare);

bool CheckInputSize(string a);
void Swap(int &a, int &b);
void Execute_CMD1(string algo, string filename, string para);
void Execute_CMD2(string ALGO_1, string input_size, string input_order, string para);
void Execute_CMD3(string ALGO_1, string input_size, string para);
void Execute_CMD4(string ALGO_1, string ALGO_2, string filename);
void Execute_CMD5(string ALGO_1, string ALGO_2, string input_size, string para);