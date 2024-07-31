#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

double calcMedian(vector<int> v, int d)
{
    if (d % 2 == 1)
        return v[d / 2];
    else
        return (v[d / 2] + v[d / 2 - 1]) / 2.0;
}
size_t findValue(vector<size_t> freq, size_t value)
{
    for (size_t i = 0; i < freq.size(); i++)
    {
        if (freq[i] == value)
        {
            return i;
        }
    }
    return 0;
}
// muốn tìm được trung vị thì
// 1. cần sắp xếp:
// 2.1 với số lượng lẻ -> lấy cái ở giữa
// 2.2 số chắn -> lấy trung bình hai số ở giữa
int activityNotifications(vector<int> expenditure, int d)
{
    /**
     * cách 3:
     * - 1. Finding Median using Counting Sort:
     * duyệt qua mảng số lần xuất hiện, ta được số mong muốn
     * Lưu ý:
     * cách này không vượt qua test case:
        5 3
        10 20 30 40 50
     * do gap qua lớn giữa hai số ?,
     * khiến cho cách tính: expenditure[i] >= tmp  (tmp = j + 1; (không đúng ở đoạn này))
     */

    // gốc: 2 3 4 2 3 6 8 4 5
    // n=9, d =5
    /**
     * 1. bảng tần suất (<d)
     *    - 0  1  2  3  4  5  6  7  8  (index)  // lưu ý, cần tạo mảng với size >= max value
     *    - 0  0  2  2  1  0  0  0  0  (số lần xuất hiện)
     * ví dụ: số 1 xuất hiện 3 lần
     */
    std::vector<size_t> freq(201);
    size_t i = 0;
    while (i < d) // lưu ý: ở đây là nhỏ hơn d, (lý do, ta lấy d cái đầu để tìm median những cái đầu trước -> tiếp đến cộng trừ để tìm median những cái sau nữa)
    {
        freq[expenditure[i]]++;
        i++;
    }
    /**
     * 2. chuyển bảng tần suất về bảng tần suất cộng dồn
     *    - 0  1  2  3  4  5  6  7  8  (index)
     *    - 0  0  2  2  1  0  0  0  0  (số lần xuất hiện)
     *    - 0  0  2  4  5  0  0  0  0  (số lần xuất hiện, cộng dồn, chỉ của d phần tử)
     */
    for (size_t j = 1; j < freq.size(); ++j) // chú ý: lúc cộng dồn thì phải cộng hết cả mảng, do vẫn phục vụ quá trình tính toán lúc sau
    {
        freq[j] += freq[j - 1];
    }

    size_t cnt = 0; // số lần tiêu thụ gấp đôi median d ngày trước
    double tmp;     // median
    size_t j;
    /**
     * 3. duyệt qua từng phần từ, start = 0 của mảng gốc
     */
    while (i < expenditure.size()) // lúc này i =d rồi (biến global, được cộng dồn từ trước)
    {
        // 3.1 tìm ra j
        // trong mảng (số lần xuất hiện, cộng dồn) -> đây chính là giá trị median
        // freq.size() : 201 và (freq[j] < d / 2); giá trị lần xuất hiện < d / 2 (chỉ mục ở giữa)
        // mục tiêu lúc này là lấy j; j là vị trí chưa median trong bảng tần suất
        // ví dụ: d = 5 -> giữa là 5/2 ~ 2
        // -> tại vị trí có giá trị 5/2 ~ 2 (từ bảng số lần xuất hiện, cộng dồn) -> index > 5/2 -> nằm giữa (median) là 2
        for (j = 0; (j < freq.size()) && (freq[j] < d / 2); ++j)
        {
            // cout << j << endl;
        };
        // 3.2 tính toán median
        // tmp: số median ?
        if (freq[j] == d / 2) // nếu trùng,
        {                     //
            tmp = j + 1;      // lên 1 có vẻ không đủ và đúng;      // tại sao cần cộng 1, với trường hợp bằng ??
            if (d % 2 == 0)   // do là chẵn nên median = trung bình
            {                 //
                tmp += j;     // cộng thành phần trước đó?
                tmp /= 2;     // lấy trung bình
            }
        }
        else // khác
        {
            tmp = j;                                             // tại sao không cộng 1 với trường hợp khác?
            if (d % 2 == 0)                                      // do là chẵn nên median = trung bình
            {                                                    //
                tmp += (freq[j - 1] + 1 == freq[j] ? j - 1 : j); //??? chưa hiểu lắm
                tmp /= 2;                                        // lấy trung bình
            }
        }
        tmp *= 2;
        cnt = cnt + (expenditure[i] >= tmp); // số lần vượt ngưỡng
        // 3.3 cập nhật lại bảng tần số
        // tương ứng cửa số trượt
        /**
         * Duyệt lại qua cả mảng tần số, bắt đầu từ phần tử đầu tiên của mảng d (nhỏ)
         * Mục đích:
         * - loại bỏ tần số của phần từ đầu tiên đi, cái mà đã không còn ở trong mảng d nhỏ tiếp theo
         * + tăng tần số lên phù hợp với phần tử tiếp theo trong mảng d
         */
        // Bằng cách này ta chỉ, trừ đi tần suất của thằng đầu tiên, cái mà đã bị loại bỏ khi dùng cửa số trượt
        // -> Từ đó tránh việc duyệt cả mảng.
        // -> Cũng như chỉ trừ những thành phần công dồn tiếp theo.
        for (j = expenditure[i - d]; j < freq.size(); ++j)
        {
            --freq[j];
        }
        // Tần suất của thành phần kế tiếp được cộng dồn vào
        for (j = expenditure[i]; j < freq.size(); ++j)
        {
            ++freq[j];
        }
        // tăng i lên, duyệt mảng tới
        i++;
    }

    return cnt;

    // // 9 5
    // // 2 3 4 2 3 6 8 4 5
    /**
     * cách 1:
     * - chưa tối ưu do sort quá nhiều.
     * - sort + for -> n^2
     */
    // int arrSize = expenditure.size();
    // float median;
    // int actNotifi = 0;
    // for (int i = d; i < arrSize; i++)
    // {
    //     sort(expenditure.begin() + i - d, expenditure.begin() + i - 1); // chưa tối ưu
    //     if (d % 2 == 1)
    //     {
    //         median = expenditure[i - (d / 2 + 1)];
    //     }
    //     else if (d % 2 == 0)
    //     {
    //         median = round(floor(expenditure[i - (d / 2) - 1] + expenditure[i - (d / 2)])) / 2;
    //     }
    //     if (expenditure[i] / median >= 2)
    //     {
    //         actNotifi++;
    //     }
    // }
    // return actNotifi;

    // /**
    //  * cách 2:
    //  * - thỏa mãn
    //  */
    // vector<int> v;
    // double median = 0;
    // int notifications = 0;

    // int n = expenditure.size();
    // if (n <= d)
    //     return 0;

    // for (int i = 0; i < d; i++)
    // {
    //     v.push_back(expenditure[i]);
    // }

    // sort(v.begin(), v.end()); //

    // for (int i = d; i < n; i++)
    // {
    //     median = calcMedian(v, d);
    //     if (expenditure[i] >= (2 * median))
    //         notifications++;
    //     v.erase(find(v.begin(), v.end(), expenditure[i - d]));

    //     // binary search
    //     auto it = lower_bound(v.begin(), v.end(), expenditure[i]);
    //     v.insert(it, expenditure[i]);
    // }

    // return notifications;
}

int main()
{

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++)
    {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
