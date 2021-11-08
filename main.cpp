#include <iostream>
#include <chrono>
#include "functions.h"

using namespace std;

int main()
{
    int compare = 0;
    int n = 10000;
    int a[n];
    GenerateRandomData(a, n);
    MergeSort_Compare(a, n, 0, n - 1, compare);
    cout << compare;
    return 0;
}