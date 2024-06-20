#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
/**
 * cho một mảng
 * có thể swap bất kì 2 phần tử nào
 * tìm số lần swap ít nhất để mảng sắp xếp lại theo thứ tự tăng dần
 *
 * Note:
 * - mảng không trùng nhau
 * - bắt đầu từ 1 đến n
 */

/**
5
2 3 4 1 5
out: 3

2 3 1 4 5  -> 2,3
3 2 1 4 5  -> 0,1
1 2 3 4 5  -> 0,2


4
4 3 1 2
out: 3


7
1 3 5 2 4 6 7
out:3

 */

/**
 * Giải thích:
 * - duyệt từ đầu qua mảng
 * - cái nào không bằng tại index đó
 * -> duyệt qua mảng lần nữa để tìm ra số tương ứng index
 * -> swap số này và số đang đứng ở index không bằng
 * -> swap++
 */
int minimumSwaps(vector<int> arr)
{
    int swap = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i + 1 != arr[i]) // không bằng
        {
            int t = i;
            while (arr[t] != i + 1) // tìm ra cái bằng trong mảng
            {
                t++;
            }
            int temp = arr[t]; // swap
            arr[t] = arr[i];
            arr[i] = temp;
            swap++;
        }
    }
    return swap;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    cout << res << "\n";

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y)
                                      { return x == y and x == ' '; });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
