#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximumToys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY prices, các giá
 *  2. INTEGER k, số tiền có để mua
 */

int maximumToys(vector<int> prices, int k)
{
    // cách 1:
    // sắp xếp
    // và lấy tổng lại
    // -> tốn time

    // cách 2:
    //

    // 7 50
    // 1 12 5 111 200 1000 10

    // 1 push remain 49
    // if(1 >12, swap)
    // 12 push remain 49 - 12 = 37
    //

    // my sort using buddle sort algorithm
    //  for (int i = 0; i < prices.size(); i++)
    //  {
    //      for (int j = 0; j < prices.size() - i - 1; j++)
    //      {
    //          if (prices[j] > prices[j + 1])
    //          {
    //              int temp = prices[j];
    //              prices[j] = prices[j + 1];
    //              prices[j + 1] = temp;
    //          }
    //      }
    //  }
    sort(prices.begin(), prices.end()); // tối ưu tốt để giảm thời gian
    int numToys = 0;
    for (auto i : prices)
    {
        if (k - i < 0)
        {
            break;
        }
        else
        {
            k = k - i;
            numToys++;
        }
    }
    return numToys;
}

int main()
{

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string prices_temp_temp;
    getline(cin, prices_temp_temp);

    vector<string> prices_temp = split(rtrim(prices_temp_temp));

    vector<int> prices(n);

    for (int i = 0; i < n; i++)
    {
        int prices_item = stoi(prices_temp[i]);

        prices[i] = prices_item;
    }

    int result = maximumToys(prices, k);

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
