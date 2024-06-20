#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */
/**
 *
5 3
1 2 100
2 5 100
3 4 100

1 2 3 4 5

0 0 0 0 0
100 100 0 0 0
100 200 100 100 100
100 200 200 200 100

-> số lớn nhất sau các lần thực hiện là 200
 */

// tìm max 1, min 2 của 2 cặp liền nhau

// cách đồ đá nhất:
// 1. Duyệt qua mảng (trogn duyệt có duyện qua k phần tử để cộng) -> cộng O(n*k)
// 2. Tìm max của mảng

// cách 1: timeout
// O(n*k)
// long arrayManipulation(int n, vector<vector<int>> queries)
// {
//     long maxResult = 0;
//     for (int i = 0; i < n; i++)
//     {
//         long newItem = 0;
//         for (int j = 0; j < queries.size(); j++)
//         {
//             if (i + 1 >= queries[j][0] && i + 1 <= queries[j][1])
//             {
//                 newItem += queries[j][2];
//             }
//         }
//         maxResult = max(newItem, maxResult);
//     }
//     return maxResult;
// }

// cách 2: timeout
// O(m*k)
// long arrayManipulation(int n, vector<vector<int>> queries)
// {
//     vector<long> arr(n, 0);
//     long maxResult = 0;
//     for (int i = 0; i < queries.size(); i++)
//     {
//         for (int j = queries[i][0]; j <= queries[i][1]; j++)
//         {
//             arr[j - 1] += (long)queries[i][2];
//             maxResult = max(arr[j - 1], maxResult);
//         }
//     }
//     return maxResult;
// }

// cách 3: đúng nhất, khá thần kì
// O(m+n)
long arrayManipulation(int n, vector<vector<int>> queries)
{
    vector<long> arr(n + 1, 0);
    for (int i = 0; i < queries.size(); i++)
    {
        arr[queries[i][0] - 1] += (long)queries[i][2];
        arr[queries[i][1]] -= (long)queries[i][2];
    }
    long maxResult = 0;
    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxResult = max(sum, maxResult);
    }
    return maxResult;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m);

    for (int i = 0; i < m; i++)
    {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++)
        {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    long result = arrayManipulation(n, queries);

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
