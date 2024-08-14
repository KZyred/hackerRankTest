/**
 * Yêu cầu:
    - Cho mảng n phần tử, số nguyên k.
    - Tìm 2 phần tử sao cho hiệu của chúng là số nguyên k.

 * Test Case:
        5 2
        1 5 3 4 2
    Output:
        3 1 2
        2 1 3

 *  Ý tưởng:
        - 1. Vét cạn
        - 2. unorder_map: giống bài toán tổng

 *  Nhận xét ý tưởng:
   - Ý tưởng:
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int pairs(int k, vector<int> arr)
{
    // int result = 0;
    // for (int i = 0; i < arr.size() - 1; i++)
    // {
    //     for (int j = i + 1; j < arr.size(); j++)
    //     {
    //         if (abs(arr[j] - arr[i]) == k)
    //         {
    //             result++;
    //         }
    //     }
    // }
    // return result;

    // 1 3 2
    // 3 1 2

    // unordered_map<int, int> arr_map;
    // int result = 0;
    // for (auto i : arr)
    // {
    //     arr_map[i]++;
    // }
    // for (auto i : arr)
    // {
    //     arr_map[i + k];
    //     arr_map[i + k]++;
    // }

    int result = 0;
    unordered_map<int, int> arr_map;
    for (int i = 0; i < arr.size(); i++)
    {
        arr_map[arr[i]]++;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        int complement = k + arr[i];
        if (arr_map.find(complement) != arr_map.end() && arr_map[complement] != i)
        {
            result++;
            continue;
        }
        complement = arr[i] - k;
        if (arr_map.find(complement) != arr_map.end() && arr_map[complement] != i)
        {
            result++;
            continue;
        }
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pairs(k, arr);

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
