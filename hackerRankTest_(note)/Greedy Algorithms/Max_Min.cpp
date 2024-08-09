/**
 * Yêu cầu:
    - Cho mảng arr, và số nguyên k (chú ý các element trong Arr có thể giống nhau)
    - Tạo các sub arr gồm k số nguyên
    - Tìm ra min: max(subArr_1) - min(subArr_1)
 *
 * Test Case:
    7
    3
    10
    100
    300
    200
    1000
    20
    30
    -> out: 20  = max(10,20,30) - min(10,20,30) = 30 - 10 = 20 (because k=3)

    5
    2
    1
    2
    1
    2
    1
    -> out: 0 = max(2,2) - min(2,2) = max(1,1) - min(1,1) (because k = 2)

 *  Ý tưởng:
    1. Sort
    -> max - min bé nhất khi max - min có distance như nhau
    -> Chú ý sub array có length = k


    -> Tìm ra hai số có khoảng cách bé nhất,
    -> thỏa mãn derdr đ



 *
 *  Nhận xét ý tưởng:
 * - Ý tưởng: ý tưởng hay, dễ hiểu
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int maxMin(int k, vector<int> arr)
{
    sort(arr.begin(), arr.end(), greater<int>());
    int min = arr[0];
    for (int i = 0; i <= (arr.size() - k); i++)
    {
        int tempSub = arr[i] - arr[i + k - 1];
        if (tempSub < min)
        {
            min = tempSub;
        }
    }
    return min;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
