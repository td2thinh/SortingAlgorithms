#include <iostream>
#include <chrono>

using namespace std;

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

void MergeSort_Timing(int a[], int n)
{
    //Execution Time measuring codes are retrieved from: How to Measure C++ Time Intervals | Pluralsight. (2020, February 5). Pluralsight. https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
    auto start = std::chrono::high_resolution_clock::now();
    MergeSort(a, n, 0, n - 1);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
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
