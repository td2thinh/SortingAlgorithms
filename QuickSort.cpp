#include <iostream>
#include <chrono>

using namespace std;
int medianThree(int a, int b, int c)
{
    if ((a > b) ^ (a > c))
        return a;
    else if ((b < a) ^ (b < c))
        return b;
    else
        return c;
}

int partition(int a[], int first, int last)
{
    int mid = (first + last) / 2;
    int i = first;
    int j = last;
    int pivot = medianThree(a[first], a[mid], a[last]);
    int temp;
    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}
void QuickSort(int a[], int first, int last)
{
    int index = partition(a, first, last);
    if (first < index - 1)
        QuickSort(a, first, index - 1);
    if (index < last)
        QuickSort(a, index, last);
}

void QuickSort_Timing(int a[], int n)
{
    //Execution Time measuring codes are retrieved from: How to Measure C++ Time Intervals | Pluralsight. (2020, February 5). Pluralsight. https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
    auto start = std::chrono::high_resolution_clock::now();
    QuickSort(a, 0, n - 1);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}

int medianThree_Compare(int a, int b, int c, int &compare)
{
    if ((a > b) ^ (a > c))
    {
        compare += 2;
        return a;
    }
    else if ((b < a) ^ (b < c))
    {
        compare += 4;
        return b;
    }
    else
    {
        compare += 4;
        return c;
    }
}
int partition_Compare(int a[], int first, int last, int &compare)
{
    int mid = (first + last) / 2;
    int i = first;
    int j = last;
    int pivot = medianThree_Compare(a[first], a[mid], a[last], compare);
    int temp;
    while (i <= j)
    {
        while (++compare && a[i] < pivot)
            i++;
        while (++compare && a[j] > pivot)
            j--;
        if (++compare && i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}
void QuickSort_Compare(int a[], int first, int last, int &compare)
{
    int index = partition_Compare(a, first, last, compare);
    if (++compare && first < index - 1)
        QuickSort_Compare(a, first, index - 1, compare);
    if (++compare && index < last)
        QuickSort_Compare(a, index, last, compare);
}