/**
 * Yêu cầu:
    * - cho n bó hoa và k người
    * - yêu cầu:
    *   + n có thể nhỏ hơn k
    *   + buộc k người phải mua hết n bó hoa
    * -> nếu n==k -> tổng
    * -> nếu k < n -> sẽ có ít nhất một người phải mua ít nhất 2 lần
    *
    * -> mỗi người mua lần thứ 2 trở đi công thức sẽ là:
    * + lần 1: (0 + 1)* giá gốc1
    * + lần 2: (1 + 1)* giá gốc2
    * ...
 *  => như vậy yêu cầu: lượng tiền bỏ ra mua hoa là tối thiểu, và phải mua hết chỗ hoa này
 *
 * Test Case:
    5 3
    1 3 5 7 9
    -> out: 29 = 5 + 7 + 9 + (1+1)*1 + (1+1)*3

    3 2
    2 5 6
    -> out: 15 = 5 + 6 + (1+1)*2

 *  Ý tưởng:
    1. Buộc phải sort lại theo thứ tự từ lớn tới bé
        - Chiến thuật mua hết loại hoa giá cao trước
        - Lý do: loại hoa giá thấp còn lại sẽ được tính theo công thức bội -> giảm được chi phí
    2. Lặp qua và cộng dồn lại
 *
 *  Nhận xét ý tưởng:
 * - Ý tưởng: ý tưởng hay, dễ hiểu
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<string> split_string(string);

int getMinimumCost(int k, vector<int> c)
{
    // sắp xếp lại vector
    sort(c.begin(), c.end(), greater<int>()); // giảm dần
    // khởi taọ size, giá ban đầu, item trước đó
    int len = c.size();                      // lượng hoa phải mua hết
    int price = 0;                           // số tiền cần chi trả
    int prevPurch = 0;                       // tỉ lệ tăng giá (nếu chưa mua hết hoa)
    for (int i = 0, j = k - 1; i < len; i++) // khởi tạo ban đầu j= k-1
    {
        price += c[i] * (prevPurch + 1); // giá được cộng dồn
        if (i == j)                      // nếu lượng người mua nhỏ hơn tổng số hoa
        {
            prevPurch++; // cần tăng lãi lên
            j += k;      // là do khi hết một lượt người mua, mà vẫn còn hoa -> như vậy lượt tới tính là mua lần 2,3,... -> prev++
        }
    }
    return price;
}
int main()
{
    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int minimumCost = getMinimumCost(k, c);

    cout << minimumCost << "\n";

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
