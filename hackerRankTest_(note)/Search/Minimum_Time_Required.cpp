/**
 * Yêu cầu:
    - Cho mảng n máy móc, số sản phẩm cần đạt.
    - Danh sách các ngày tối thiểu vận hành để ra một sản phẩm của máy móc.

Chú ý: mỗi phần tử trong mảng là duy nhất.

 * Test Case:
        2 5
        2 3
    Output:
        6

 *  Ý tưởng:
        - 1. Yêu cầu tính toán mạnh với phân số -> lời giải sai
            -> nếu chỉ tìm điều kiện bound dưới
            -> yêu cầu while để tiếp tục tìm
            -> lý do phải tiếp tục dùng while là do có sai số sinh ra khi dùng float
            (nhiều phân số cộng với nhau gây sai số cộng dồn -> lỗi)

        - 2. Ý tưởng dựa vào việc sử dụng "Binary Search."
            -> Thời gian tối đa có thể cần thiết để tạo ra m sản phẩm
                sẽ là thời gian tối đa trong mảng, amax, nhân với m: Ví dụ amax * m.
            -> Vì vậy, hãy sử dụng tìm kiếm nhị phân trong khoảng từ 1 đến amax * m
                từ đó, ta tìm thời gian tối thiểu tạo ra m sản phẩm.


 *  Nhận xét ý tưởng:
   - Ý tưởng:
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<string> split_string(string);

long minTime(vector<long> machines, long goal)
{
    long maxVal = INT_MIN;
    for (auto i : machines)
    {
        maxVal = max(maxVal, i);
    }

    long low = 1;
    long high = maxVal * goal;

    while (low < high)
    {
        long mid = (low + high) >> 1;
        long items = 0;
        for (auto i : machines)
        {
            items += mid / i;
        }

        if (items < goal)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return high;
}

int main()
{
    string nGoal_temp;
    getline(cin, nGoal_temp);

    vector<string> nGoal = split_string(nGoal_temp);

    int n = stoi(nGoal[0]);

    long goal = stol(nGoal[1]);

    string machines_temp_temp;
    getline(cin, machines_temp_temp);

    vector<string> machines_temp = split_string(machines_temp_temp);

    vector<long> machines(n);

    for (int i = 0; i < n; i++)
    {
        long machines_item = stol(machines_temp[i]);

        machines[i] = machines_item;
    }

    long ans = minTime(machines, goal);

    cout << ans << "\n";

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
