#include <iostream>
#include <cstring>
#include <chrono>
using namespace std;

void CountingSort(int a[], int n)
{
    //https://github.com/HaiDuc0147/sortingAlgorithm
    //https://www.geeksforgeeks.org/counting-sort/#:~:text=Counting%20sort%20is%20a%20sorting,object%20in%20the%20output%20sequence.

    int max = a[0], min = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    int range = max - min + 1;
    int count[range + 1];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++)
        ++count[a[i] - min];

    for (int i = 1; i <= range; i++)
        count[i] += count[i - 1];

    int *temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        temp[count[a[i] - min] - 1] = a[i];
        --count[a[i] - min];
    }

    for (int i = 0; i < n; i++)
        a[i] = temp[i];

    delete[] temp;
}

double CountingSort_Timing(int arr[], int n)
{
    //Execution Time measuring codes are retrieved from: How to Measure C++ Time Intervals | Pluralsight. (2020, February 5). Pluralsight. https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
    auto start = std::chrono::high_resolution_clock::now();
    CountingSort(arr, n);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    return elapsed.count();
}

void CountingSort_Comparison(int a[], int n, int &compare)
{
    compare = 0;

    int max = a[0], min = a[0];

    for (int i = 1; ++compare, i < n; i++)
    {
        if (++compare, a[i] > max)
            max = a[i];
        if (++compare, a[i] < min)
            min = a[i];
    }

    int range = max - min + 1;
    int count[range + 1];
    memset(count, 0, sizeof(count));

    for (int i = 0; ++compare, i < n; i++)
        ++count[a[i] - min];

    for (int i = 1; ++compare, i <= range; i++)
        count[i] += count[i - 1];

    int *temp = new int[n];
    for (int i = 0; ++compare, i < n; i++)
    {
        temp[count[a[i] - min] - 1] = a[i];
        --count[a[i] - min];
    }

    for (int i = 0; ++compare, i < n; i++)
        a[i] = temp[i];

    delete[] temp;
}
