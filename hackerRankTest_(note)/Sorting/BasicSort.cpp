#include <iostream>
#include <vector>

void BubbleSort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 1; j < arr.size() - i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }
}

void SelectionSort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

void InsertionSort(std::vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int j = i;
        while (j)
        {
            if (arr[j] < arr[j - 1])
            {
                std::swap(arr[j], arr[j - 1]);
            }
            else
            {
                break;
            }
            j--;
        }
    }
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
    InsertionSort(arr);
    for (const auto &i : arr)
    {
        std::cout << i << " ";
    }
    return 0;
}