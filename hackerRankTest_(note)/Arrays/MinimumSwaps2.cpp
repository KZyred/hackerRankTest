#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr)
{
    // // câu hỏi:
    // // 1. làm thế nào để biết swap cái nào trước, sau -> quy luật gì không
    // // 2. liệu chỉ có một cách duy nhất để swap theo thứ tự không?! -> thực nhiệm chỉ ra rằng không, có nhiều hơn một cách swap đạt được tối thiểu

    // // solutions:
    // //  1. nhận thấy cứ swap cái thằng tối tiểu về đúng vị trí của nó rồi cứ tiếp tục cho hết mảng là đạt được target -> sai, khó tìm thằng tối thiểu
    // // nhận thấy rằng phải tốn ít nhất n%2 số lần swap? -> sai

    // int swap = 0;

    // // 1. duyệt qua mảng
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     // 2. check vị trí
    //     if (i + 1 != arr[i])
    //     {
    //         // 3. mấu chốt
    //         // 3.1 lấy index, tìm ra thằng trùng
    //         // - swap lần lượt từ đầu tới cuối
    //         // - mặc định sẽ được xếp đúng hàng
    //         // nhìn chung không khó, cần duyệt n! lần;
    //         int t = i;
    //         while (arr[t] != i + 1)
    //         {
    //             t++;
    //         }
    //         // swap
    //         int temp = arr[t];
    //         arr[t] = arr[i];
    //         arr[i] = temp;
    //         // result: số lần swap
    //         swap++;
    //     }
    // }
    // return swap;

    // tôi tự làm lại theo cách hiểu của chính tôi trước đó tôi đã làm.
    int swapTms = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        // 1. check
        if (arr[i] != (i + 1))
        {
            // 2. find index
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[j] == (i + 1))
                {
                    int temp;
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    swapTms++;
                    break; // thêm cái này phát là đỡ time out luôn
                }
            }
        }
    }
    return swapTms;
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
