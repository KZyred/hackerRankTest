/**
 * 1. Yêu cầu:
 * - Query được mô tả có cấu trúc như sau:
        + 1 x : thêm x vào data structure
        + 2 y : Xóa y thuộc data structure (nếu y tồn tại)
        + 3 z : Kiểm ra xem trong data structure có bất kì số nguyên nào lặp lại z lần không. If yes, print 1 else 0.
 *
 * 2. Test Case:
        8       // số lần query
        1 5
        1 6
        3 2
        1 10
        1 10
        1 6
        2 5
        3 2
    -> out:
        0
        1
 *
 * 3. Ý tưởng:
 * - Ý tưởng ban đầu của tôi: chỉ dùng một unordered_map -> tần số được công dồn nếu trùng -> check có tần số mong muốn -> true
 * - Ý tưởng đúng:
 *      + sử dụng 2 order_map -> sẽ giảm được thời gian xử lý
 *          - 1 order_map: lưu tần số xuất hiện của kí tự
 *          - 1 order_map: lưu tần số của tần số xuất hiện trên
 * 4. Nhận xét ý tưởng:
 * -
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// /**
//  * my idea
//  */
// vector<int> freqQuery(vector<vector<int>> queries)
// {
//     unordered_map<int, int> freqMap;
//     vector<int> result;
//     for (int i = 0; i < queries.size(); i++)
//     {
//         int valQuery = queries[i][1];
//         switch (queries[i][0])
//         {
//         case 1:
//             freqMap[valQuery]++;
//             break;
//         case 2:
//             freqMap[valQuery]--;
//             break;
//         case 3:
//         {
//             bool checkVal = false;
//             for (auto &it : freqMap)
//             {
//                 if (it.second == valQuery)
//                 {
//                     checkVal = true;
//                     break;
//                 }
//             }
//             result.push_back(checkVal == true ? 1 : 0);
//             break;
//         }
//         default:
//             break;
//         }
//     }
//     return result;
// }

/**
 * Hackerank idea
 * ví dụ:
        8
        1 5
        1 6
        3 2
        1 10
        1 10
        1 6
        2 5
        3 2

count_map =
    [10] = 2
    [6]  = 2
    [5]  = 0

frequency_map =
    [2] = 2
    [1] = 0
    [0] = -2
 *
Giải thích:
    - Với Type bằng 1: thêm dữ liệu -> chứng tỏ các tần số xuất hiện sẽ biến đổi
        + tần suất của tần suất xuất hiện -> thay đổi (cần giảm cũ -> sau đó cập nhật lại mới)
        + tấn suất xuất hiện của kí tự tăng lên

    --> Nhìn chung để update tần số của tần số: Sẽ có combo sau: (với type 1 và 2)
            freOfCnt_map[count_map[valDat]]--;
            ...(tăng hoặc giảm...);
            freOfCnt_map[count_map[valDat]]++;

    - Với type 3: ta chỉ việc kiểm tra

    --> giảm thời gian check lặp trong type 3
 */
vector<int> freqQuery(vector<vector<int>> queries)
{
    int type;                              // loại query
    int valDat;                            // dữ liệu (trong query)
    vector<int> query;                     // mảng cần query: type + chứa dữ liệu
    vector<int> query_results;             // kết quả
    unordered_map<long, int> count_map;    // tần suất xuất hiện các kí tự giống nhau
    unordered_map<int, long> freOfCnt_map; // tần suất của tần suất xuất hiện

    for (int i = 0; i < queries.size(); i++)
    {
        query = queries[i];
        type = query[0];
        valDat = query[1];
        switch (type)
        {
        case 1:
            // giảm cũ, (ví dụ: ban đầu xuất hiện 1 lần -> thêm giống nhau -> xuất hiện 2 lần)
            // [1] : 1  --> [1] : 0
            // [2] : 0      [2] : 1
            freOfCnt_map[count_map[valDat]]--; // giảm cũ, (ví dụ: ban đầu xuất hiện 1 lần -> thêm giống nhau -> xuất hiện 2 lần)
            count_map[valDat]++;               // tăng như bình thường kí tự xuất hiện
            freOfCnt_map[count_map[valDat]]++; // tăng lần suất hiện lên
            break;
        case 2:
            int current_count = count_map[valDat]; // tần suất xuất hiện kí tự
            if (current_count > 0)                 // buộc check, không thể bỏ (số lần xuất hiện)
            {                                      //
                freOfCnt_map[count_map[valDat]]--; // giảm tần suất của tần suất (hiện tại)
                count_map[valDat]--;               // giảm tần suất xuất hiện kí tự
                freOfCnt_map[count_map[valDat]]++; // tăng lần suất hiện lên
            }
            break;
        case 3:
            query_results.push_back((freOfCnt_map[valDat] > 0) ? 1 : 0);
            break;
        default:
            break;
        }
    }
    return query_results;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++)
    {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++)
        {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];

        if (i != ans.size() - 1)
        {
            cout << "\n";
        }
    }

    cout << "\n";

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
