#include <iostream>
#include <vector>

// sắp xếp trộn
int pivot(std::vector<int> &arr, int low, int high)
{
    int pivot(low), iSwap(low);
    for (int i = low + 1; i <= high; i++)
    {
        if (arr[pivot] > arr[i])
        {
            iSwap++;
            std::swap(arr[iSwap], arr[i]);
        }
    }
    std::swap(arr[iSwap], arr[pivot]);
    return iSwap;
}

// đệ quy chia
void quickSort(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int piv = pivot(arr, left, right);

    quickSort(arr, left, piv - 1);
    quickSort(arr, piv + 1, right);
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (auto &i : arr)
    {
        std::cin >> i;
    }
    //
    quickSort(arr, 0, arr.size() - 1);
    for (auto &i : arr)
    {
        std::cout << i << " ";
    }
    return 0;
}