#include "header.h"
#include <iostream>
using namespace std;
//Shell sort----------------------------------------------------------------------------------------------
int ShellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

void ShellSort_Comparison(int arr[], int n, int &compare)
{
    compare = 0;
    for (int gap = n / 2; ++compare, gap > 0; gap /= 2)
    {

        for (int i = gap; ++compare, i < n; i += 1)
        {

            int temp = arr[i];
            int j;
            for (j = i; ++compare, j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

double ShellSort_Timing(int arr[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    ShellSort(arr, n);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, milli> elapsed = finish - start;
    return elapsed.count();
}

//Radix sort----------------------------------------------------------------------------------------------
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

//Shaker sort----------------------------------------------------------------------------------------------
void ShakerSort(int a[], int n)
{
    int left = 0;
    int right = n - 1;
    int k = 0;
    for (int i = left; i <= right; i++)
    {
        bool swapped = false;
        //day max ve cuoi mang
        for (int j = left; j < right; j++)
            if (a[j] > a[j + 1])
            {
                swapped = true;
                Swap(a[j], a[j + 1]);
                k = j;
            }
        if (!swapped)
            return;
        right = k;
        //day min ve dau mang
        swapped = false;
        for (int j = right; j > left; j--)
            if (a[j] < a[j - 1])
            {
                swapped = true;
                Swap(a[j], a[j - 1]);
                k = j;
            }
        if (!swapped)
            return;
        left = k;
    }
}

double ShakerSort_Timing(int a[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    ShakerSort(a, n);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, milli> elapsed = finish - start;
    return elapsed.count();
}

void ShakerSort_Compare(int a[], int n, int &count_compare)
{
    int left = 0;
    int right = n - 1;
    int k = 0;
    for (int i = left; ++count_compare && i <= right; i++)
    {
        bool swapped = false;
        //day max ve cuoi mang
        for (int j = left; ++count_compare && j < right; j++)
            if (++count_compare && a[j] > a[j + 1])
            {
                swapped = true;
                Swap(a[j], a[j + 1]);
                k = j;
            }
        if (++count_compare && !swapped)
            return;
        right = k;
        //day min ve dau mang
        swapped = false;
        for (int j = right; ++count_compare && j > left; j--)
            if (a[j] < a[j - 1])
            {
                swapped = true;
                Swap(a[j], a[j - 1]);
                k = j;
            }
        if (++count_compare && !swapped)
            return;
        left = k;
    }
}

//Selection sort----------------------------------------------------------------------------------------------
void SelectionSort(int a[], int n)
{
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        Swap(a[min_idx], a[i]);
    }
}

double SelectionSort_Timing(int a[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    SelectionSort(a, n);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, milli> elapsed = finish - start;
    return elapsed.count();
}

void SelectionSort_Compare(int a[], int n, int &count_compare)
{
    // One by one move boundary of unsorted subarray
    for (int i = 0; ++count_compare && i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; ++count_compare && j < n; j++)
            if (++count_compare && a[j] < a[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        Swap(a[min_idx], a[i]);
    }
}
//Insertion sort----------------------------------------------------------------------------------------------
void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

double InsertionSort_Timing(int a[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    InsertionSort(a, n);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, milli> elapsed = finish - start;
    return elapsed.count();
}

void InsertionSort_Compare(int a[], int n, int &count_compare)
{
    for (int i = 1; ++count_compare && i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while ((++count_compare && a[j] > key) && (++count_compare && j >= 0))
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

//Heap sort----------------------------------------------------------------------------------------------

void Heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        Swap(a[i], a[largest]);

        Heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        Swap(a[0], a[i]);

        Heapify(a, i, 0);
    }
}

double HeapSort_Timing(int a[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    HeapSort(a, n);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, milli> elapsed = finish - start;
    return elapsed.count();
}

void Heapify_Compare(int a[], int n, int i, int &count_compare)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if ((++count_compare && l < n) && (++count_compare && a[l] > a[largest]))
        largest = l;

    if ((++count_compare && r < n) && (++count_compare && a[r] > a[largest]))
        largest = r;

    if (++count_compare && largest != i)
    {
        Swap(a[i], a[largest]);

        Heapify_Compare(a, n, largest, count_compare);
    }
}

void HeapSort_Compare(int a[], int n, int &count_compare)
{
    for (int i = n / 2 - 1; ++count_compare && i >= 0; i--)
        Heapify_Compare(a, n, i, count_compare);

    for (int i = n - 1; ++count_compare && i >= 0; i--)
    {
        Swap(a[0], a[i]);
        Heapify_Compare(a, i, 0, count_compare);
    }
}

//Bubble sort----------------------------------------------------------------------------------------------
void BubbleSort(int a[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                Swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}

double BubbleSort_Timing(int a[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    BubbleSort(a, n);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, milli> elapsed = finish - start;
    return elapsed.count();
}

void BubbleSort_Compare(int a[], int n, int &count_compare)
{
    bool swapped;
    for (int i = 0; ++count_compare && i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; ++count_compare && j < n - i - 1; j++)
        {
            if (++count_compare && a[j] > a[j + 1])
            {
                Swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (++count_compare && swapped == false)
            break;
    }
}

//Quick sort----------------------------------------------------------------------------------------------
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

double QuickSort_Timing(int a[], int n)
{
    //Execution Time measuring codes are retrieved from: How to Measure C++ Time Intervals | Pluralsight. (2020, February 5). Pluralsight. https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
    auto start = std::chrono::high_resolution_clock::now();
    QuickSort(a, 0, n - 1);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, milli> elapsed = finish - start;
    return elapsed.count();
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

//Merge sort----------------------------------------------------------------------------------------------

//Mergesort functions retrieved from: Carrano, F. M., & Henry, T. M. (2012). Data Abstraction & Problem Solving with C++: Walls and Mirrors (6th Edition) (6th ed.). Pearson.
void merge(int theArray[], int n, int first, int mid, int last)
{
    int tempArray[n]; // Temporary array
    // Initialize the local indices to indicate the subarrays
    int first1 = first;   // Beginning of first subarray
    int last1 = mid;      // End of first subarray
    int first2 = mid + 1; // Beginning of second subarray
    int last2 = last;     // End of second subarray
    // While both subarrays are not empty, copy the
    // smaller item into the temporary array

    int index = first1; // Next available location in tempArray
    while ((first1 <= last1) && (first2 <= last2))
    {
        // At this point, tempArray[first..index-1] is in order

        if (theArray[first1] <= theArray[first2])
        {

            tempArray[index] = theArray[first1];

            first1++;
        }
        else

        {

            tempArray[index] = theArray[first2];

            first2++;

        } // end if
        index++;

    } // end while
    // Finish off the first subarray, if necessary
    while (first1 <= last1)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1];

        first1++;

        index++;

    } // end while
    // Finish off the second subarray, if necessary
    while (first2 <= last2)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];

        first2++;

        index++;

    } // end for
    // Copy the result back into the original array
    for (index = first; index <= last; index++)
        theArray[index] = tempArray[index];

} // end merge

void MergeSort(int theArray[], int n, int first, int last)
{
    if (first < last)
    {
        // Sort each half

        int mid = first + (last - first) / 2; // Index of midpoint
                                              // Sort left half theArray[first..mid]
        MergeSort(theArray, n, first, mid);
        // Sort right half theArray[mid+1..last]
        MergeSort(theArray, n, mid + 1, last);
        // Merge the two halves
        merge(theArray, n, first, mid, last);

    } // end if

} // end mergeSort

double MergeSort_Timing(int a[], int n)
{
    //Execution Time measuring codes are retrieved from: How to Measure C++ Time Intervals | Pluralsight. (2020, February 5). Pluralsight. https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
    auto start = std::chrono::high_resolution_clock::now();
    MergeSort(a, n, 0, n - 1);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, milli> elapsed = finish - start;
    return elapsed.count();
}

void merge_Compare(int theArray[], int n, int first, int mid, int last, int &compare)
{
    int tempArray[n]; // Temporary array
    // Initialize the local indices to indicate the subarrays
    int first1 = first;   // Beginning of first subarray
    int last1 = mid;      // End of first subarray
    int first2 = mid + 1; // Beginning of second subarray
    int last2 = last;     // End of second subarray
    // While both subarrays are not empty, copy the
    // smaller item into the temporary array

    int index = first1; // Next available location in tempArray
    while (++compare && (first1 <= last1) && ++compare && (first2 <= last2))
    {
        // At this point, tempArray[first..index-1] is in order

        if (++compare && theArray[first1] <= theArray[first2])
        {

            tempArray[index] = theArray[first1];

            first1++;
        }
        else

        {

            tempArray[index] = theArray[first2];

            first2++;

        } // end if
        index++;

    } // end while
    // Finish off the first subarray, if necessary
    while (++compare && first1 <= last1)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1];

        first1++;

        index++;

    } // end while
    // Finish off the second subarray, if necessary
    while (++compare && first2 <= last2)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];

        first2++;

        index++;

    } // end for
    // Copy the result back into the original array

    while (++compare && index <= last)
    {
        theArray[index] = tempArray[index];
        index++;
    }

} // end merge

void MergeSort_Compare(int theArray[], int n, int first, int last, int &compare)
{

    if (++compare && first < last)
    {
        // Sort each half

        int mid = first + (last - first) / 2; // Index of midpoint
                                              // Sort left half theArray[first..mid]
        MergeSort_Compare(theArray, n, first, mid, compare);
        // Sort right half theArray[mid+1..last]
        MergeSort_Compare(theArray, n, mid + 1, last, compare);
        // Merge the two halves
        merge_Compare(theArray, n, first, mid, last, compare);

    } // end if

} // end mergeSort

//Counting sort-----------------------------------------------------------------------------------------

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
    auto start = std::chrono::high_resolution_clock::now();
    CountingSort(arr, n);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, milli> elapsed = finish - start;
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

//Flash sort-----------------------------------------------------------------------------------------

void FlashSort(int a[], int n)
{
    //https://github.com/HaiDuc0147/sortingAlgorithm

    int minVal = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int *l = new int[m];
    for (int i = 0; i < m; i++)
        l[i] = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > a[max])
            max = i;
    }
    if (a[max] == minVal)
        return;
    double c1 = (double)(m - 1) / (a[max] - minVal);
    for (int i = 0; i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }
    for (int i = 1; i < m; i++)
        l[i] += l[i - 1];
    Swap(a[max], a[0]);
    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (nmove < n - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (k < 0)
            break;
        while (j != l[k])
        {
            k = int(c1 * (flash - minVal));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++nmove;
        }
    }
    delete[] l;

    for (int i = 1; i < n; i++)
    {
        int k = i - 1;
        int key = a[i];
        while (a[k] > key && k >= 0)
        {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = key;
    }
}

double FlashSort_Timing(int arr[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    FlashSort(arr, n);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, milli> elapsed = finish - start;
    return elapsed.count();
}

void FlashSort_Compare(int a[], int n, int &compare)
{
    compare = 0;

    int minVal = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int *l = new int[m];
    for (int i = 0; ++compare, i < m; i++)
        l[i] = 0;
    for (int i = 1; ++compare, i < n; i++)
    {
        if (++compare, a[i] < minVal)
            minVal = a[i];
        if (++compare, a[i] > a[max])
            max = i;
    }
    if (++compare, a[max] == minVal)
        return;
    double c1 = (double)(m - 1) / (a[max] - minVal);
    for (int i = 0; ++compare, i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++l[k];
    }
    for (int i = 1; ++compare, i < m; i++)
        l[i] += l[i - 1];
    Swap(a[max], a[0]);
    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (++compare, nmove < n - 1)
    {
        while (++compare, j > l[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (++compare, k < 0)
            break;
        while (++compare, j != l[k])
        {
            k = int(c1 * (flash - minVal));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++nmove;
        }
    }
    delete[] l;

    for (int i = 1; ++compare, i < n; i++)
    {
        int k = i - 1;
        int key = a[i];
        while ((++compare, a[k] > key) && (++compare, k >= 0))
        {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = key;
    }
}
