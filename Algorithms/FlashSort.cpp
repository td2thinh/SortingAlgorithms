#include <ctime>
void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

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
    clock_t start, end;
    double dur;

    start = clock();
    FlashSort(arr, n);
    end = clock();
    dur = (double)(end - start) / CLOCKS_PER_SEC;

    return dur;
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
