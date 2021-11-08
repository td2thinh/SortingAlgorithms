#include <iostream>
#include <chrono>
#include "functions.h"

using namespace std;

int main()
{
    int n = 100000;
    int a[n];
    GenerateRandomData(a, n);
    MergeSort_Timing(a, n);

    return 0;
}