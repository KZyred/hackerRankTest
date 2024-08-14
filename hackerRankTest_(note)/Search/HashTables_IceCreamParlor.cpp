/**
 * Yêu cầu:
    - Cho một số tiền, danh sách giá tiền kem
    - Yêu cầu chọn ra 2 loại kem có thể mua được bằng toàn bộ số tiền này
        -> trả ra 2 id (id nhỏ trước, lớn sau),
        -> chú ý có thể có giá giống nhau (với unique ID)
        -> test case cho biết: luôn luôn sẽ có giải pháp, tìm ra 2 unique ID

 * Test Case:
        2           t = 2
        4           money = 4
        5           cost[] size n = 5
        1 4 5 3 2   cost = [1, 4, 5, 3, 2]
        0 1 2 3 4

        4           money = 4
        4           cost[] size n = 4
        2 2 4 3     cost = [2, 2, 4, 3]
        0 1 2 3

        -> Output:
        1 4
        1 2

 *  Ý tưởng:
    1.
        1.1. Buộc phải sort lại theo thứ tự từ lớn tới bé (điều này làm mất index)
            - Chiến thuật mua hết loại hoa giá cao trước
            - Lý do: loại hoa giá thấp còn lại sẽ được tính theo công thức bội -> giảm được chi phí
        1.2. Lặp qua và cộng dồn lại

    2. Sử dụng binary search là điều ngu ngốc -> chỉ cần sử dụng hashmap O(n)
        2.1 hashmap có hai cách:
            - cơ bản: two-pass
            - nâng cao: one-pass

 *  Nhận xét ý tưởng:
   - Ý tưởng: với hash map rất hay, có nghĩ tới nhưng có vẻ nghĩ vẫn hơn lông
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void whatFlavors(vector<int> cost, int money)
{
    // sort lại arr
    // lấy 1 trừ -> tìm cái còn lại ?!
    // n^2 -> nhiều query chưa chắc đã ổn
    // sort(cost.begin(), cost.end());

    // Cách 1: Brute Force
    // for (int i = 0; i < cost.size() - 1; i++)
    // {
    //     for (int j = i + 1; j < cost.size(); j++)
    //     {
    //         int remMon = money - cost[i];
    //         if (remMon == cost[j])
    //         {
    //             cout << i + 1 << " " << j + 1 << endl;
    //             return;
    //         }
    //         // if (remMon < cost[j])
    //         // {
    //         //     break;
    //         // }
    //     }
    // }

    // Cách 2: Two-pass Hash Table, ngoài ra còn cách One-pass Hash Table

    // 2.1 Nhìn nhận: Ban đầu cũng có ý tưởng này, nhưng sợ rằng có nhiều hơn 1 index có cùng một giá trị
    // Ví dụ:
    // 1
    // 4
    // 5
    // 2 4 5 3 2
    // -> output: 1 5

    // 2.2 Giải pháp: Nhưng ta thấy được rằng qua vòng lặp for, các index bị ghi đè, chỉ nhận index cuối
    // -> như vậy khi duyệt lại qua mảng, nếu 2 index có cùng giá trị mà cộng lại ra kết quả cuối
    // -> thì mọi thứ đã return rồi
    // -> thỏa mãn

    // Cho vào hash map nhưng mà đang ko đính kèm được index ?! -> giải pháp , hashMap = {value, index}
    unordered_map<int, int> cost_map;
    for (int i = 0; i < cost.size(); i++)
    {
        cost_map[cost[i]] = i;
    }
    for (int i = 0; i < cost.size(); i++)
    {
        int complement = money - cost[i];
        if (cost_map.find(complement) != cost_map.end() && cost_map[complement] != i) // tồn tại trong cost_map, và không bằng i
        {
            cout << i + 1 << " " << cost_map[complement] + 1 << endl;
            return;
        }
    }
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string money_temp;
        getline(cin, money_temp);

        int money = stoi(ltrim(rtrim(money_temp)));

        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split(rtrim(cost_temp_temp));

        vector<int> cost(n);

        for (int i = 0; i < n; i++)
        {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
