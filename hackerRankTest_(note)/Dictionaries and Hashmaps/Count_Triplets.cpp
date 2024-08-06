/**
 * Yêu cầu:
 * - Cho một chuỗi, và r là bội
 * - Tìm các chuỗi con buộc phải là 3 phần tử (index khấc nhau: i < j < k), và có cấp số nhân là r
 *
 * Test Case:
    6 3
    1 3 9 9 27 81
    -> out: 6

    5 5
    1 5 5 25 125
    -> out: 4

 *  Ý tưởng:
 *  - 1. Cách đơn giản nhất: tạo 3 vòng lặp -> tìm ra 3 phần tử (i, j , k) -> O(n^3) -> loại
 *  - 2. Sử dụng unoder_map -> duyệt qua mảng -> chia mảng thành 2 phần mỗi khi duyệt qua -> O( n*log(n) )
 *
 *  Nhận xét ý tưởng:
 * - Ý tưởng 1: 3 for -> cũng là một cái nhìn nhanh tốt (khi này tôi chưa nhìn ra)
 * - Ý tưởng 2: theo tưởng tượng như một cách rẽ sóng
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// chia hết cho r -> thương -> hash table -> thương mà sát nhau -> số cần tìm
// 1. số đầu không quan trọng -> chia hết cũng được mà không cũng được.
// số thứ 2,3 bắt buộc chia hết -> mới tìm số thứ 1

// đây là một gợi ý nhưng tôi đã không hiểu nó, cảm thấy nó làm tôi rối hơn:
// 1. Có thể được thực hiện trong O(n) -> truyền dữ liệu một lần
// 2. Không cần chia và chỉ cần nhân một lần với R
// 3. Sử dụng map(C++) hoặc dict(Java, Python) là bắt buộc -> có thể là bản đồ không có thứ tự (lưu O(logN))
// 4. Hãy thử suy nghĩ trước khi đọc một giá trị -> sau này giá trị này có phải là một phần của bộ ba không?
// 5. Không cần coi (R == 1) là trường hợp góc

// tìm số chia hết cho r hoặc chia r dư -> loại do
// sắp xếp lại ->

// Chia thành 2 nửa: trái và phải
// 1. Left Map sẽ luôn chứa các phần tử có chỉ số nhỏ hơn chỉ số hiện tại
// 2. Right Map sẽ chứa các phần tử có chỉ số lớn hơn chỉ số hiện tại.

// Hình dung như sau sẽ thấy mọi thứ đơn giản hơn:
// Với ví dụ:
// 1 3 9 9 27 81

// Việc này giống kiểu duyệt qua một mảng và lưu tần số duyệt khi rẽ qua cánh đồng

// 1 3 9 9 27 81
// *
// 1. right ôm trọn cả mảng - tổng của tất các các value = array.size() - (6)
// 2. left không có phần tử nào (rỗng)

// 1 3 9 9 27 81
// - *
// -> right mất 1 tần suất xuất hiện (5)
// -> left tăng lên 1 (1)

// long countTriplets(vector<long> arr, long r)
// {
//     unordered_map<long, long> rightMap;
//     unordered_map<long, long> leftMap;
//     long result = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         rightMap[arr[i]]++; // add vào order map
//     }
//     for (int i = 0; i < arr.size(); i++)
//     {
//         // giảm right map tương ứng đi 1
//         rightMap[arr[i]]--;  // trừ đi lúc này sẽ có tương ứng, lần lượt các phần tử bằng 0
//         if (arr[i] % r == 0) // nếu mà thằng này chia hết cho r
//         {
//             result += leftMap[arr[i] / r] * rightMap[arr[i] * r]; // số lần xuất hiện các phần tử a/r và a*r
//         }
//         leftMap[arr[i]]++;

//         // câu hỏi: tại sao lại -- right và ++ left
//         // tên gọi đúng của 2 thằng này nên là gì
//     }
//     return result;
// }

// try again with my code
long countTriplets(vector<long> arr, long r)
{
    unordered_map<long, long> rightMap;
    unordered_map<long, long> leftMap;
    long result = 0;
    for (auto i : arr)
    {
        rightMap[i]++; // khởi tạo cho right map
    }
    for (auto i : arr)
    {
        rightMap[i]--;
        if (i % r == 0)
        {
            // đã check chia hết nên i/r không sợ bị nố
            result += leftMap[i / r] * rightMap[i * r]; // điều đặc biệt và tinh tế ở dấu nhân
        }
        leftMap[i]++;
    }
    return result;
}

int main()
{
    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++)
    {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    cout << ans << "\n";

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
