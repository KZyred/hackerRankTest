// C++ Program for Mode and
// Median using Counting
// Sort technique
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// function that sort input array a[] and
// calculate mode and median using counting
// sort.
void printModeMedian(int a[], int n)
{
    // The output array b[] will
    // have sorted array
    int b[n];

    // variable to store max of
    // input array which will
    // to have size of count array
    int max = *max_element(a, a + n);

    // auxiliary(count) array to
    // store count. Initialize
    // count array as 0. Size
    // of count array will be
    // equal to (max + 1).
    int t = max + 1;
    int count[t];
    for (int i = 0; i < t; i++)
        count[i] = 0;

    // Store count of each element
    // of input array
    for (int i = 0; i < n; i++)
        count[a[i]]++;

    // mode is the index with maximum count
    int mode = 0;
    int k = count[0];
    for (int i = 1; i < t; i++)
    {
        if (count[i] > k)
        {
            k = count[i];
            mode = i;
        }
    }

    // Update count[] array with sum
    for (int i = 1; i < t; i++)
        count[i] = count[i] + count[i - 1];

    // Sorted output array b[]
    // to calculate median
    for (int i = 0; i < n; i++)
    {
        b[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    // Median according to odd and even
    // array size respectively.
    float median;
    if (n % 2 != 0)
        median = b[n / 2];
    else
        median = (b[(n - 1) / 2] +
                  b[(n / 2)]) /
                 2.0;

    // Output the result
    cout << "median = " << median << endl;
    cout << "mode = " << mode;
}

// Driver program
int main()
{
    int a[] = {1, 4, 1, 2, 7, 1, 2, 5, 3, 6};
    int n = sizeof(a) / sizeof(a[0]);
    printModeMedian(a, n);
    return 0;
}
