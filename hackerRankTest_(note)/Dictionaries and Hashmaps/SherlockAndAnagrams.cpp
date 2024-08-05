/**
 * *Đề bài:
 *  - Tìm các substring trong main string
 *  - Sao cho chúng có thể đảo với nhau ra chuỗi giống chuỗi cần tìm
 *      -> Chỉ cần tổng bằng nhau và tổng vị trí khác nhau -> OKE
 *      -> sai, các item có tổng gộp lại giống nhau chưa chắc đã có thể lặp lại giống nhau
 *
 * * Test Case:
 *  - ifailuhkqq -> 3
 *  - kkkk -> 10
 *  - cdcd -> 5
 *
 * * Ý tưởng:
 *
 *
 * * Nhận xét ý tưởng:
 * -
 *
 *
 *
 */

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/**
 * Chức năng: Kiểm ra xem chuỗi s1, có phải là chuỗi đảo ngữ không?!
 *
 */
bool isAnagram(string s1, string s2)
{
    const int lenCharFreq = 26;
    int charFreq[lenCharFreq] = {0};      // tạo mảng tần suất xuất hiện kí tự, gồm 26 items
    for (int i = 0; i < s1.length(); i++) // chú ý: s1.length() == s2.length(), đây cũng là điều kiện để kiểm tra trước khi gọi hàm isAnagram
    {                                     //
        charFreq[s1[i] - 'a']++;          // adding 1 for every character of s1
        charFreq[s2[i] - 'a']--;          // subtracting 1 for every character of s2
    }

    for (int i = 0; i < lenCharFreq; i++) // duyệt qua charFreq
    {
        // charFreq[i] == 0
        // 1. không có kí tự xuất hiện
        // 2. kí tự đã xuất hiện cả trong chuỗi 1 và chuỗi 2
        if (charFreq[i] != 0) // nếu chuỗi không phải là chuỗi đảo chữ thì sẽ có ít nhất một phần tử có giá trị khác không.
            return false;
    }
    return true; // đây là một chuỗi đảo ngữ -> true -> cnt ++

    /**
     * Không dùng được ý tưởng tính tổng, do có vẫn có trường hợp tổng như nhau nhưng không thể đảo lại
     */
    // int sumS1 = 0;
    // int sumS2 = 0;

    // for (int i = 0; i < s1.length(); i++)
    // {
    //     sumS1 += s1[i] - 'a';
    // }
    // for (int i = 0; i < s2.length(); i++)
    // {
    //     sumS2 += s2[i] - 'a';
    // }
    // if (sumS1 == sumS2)
    // {
    //     return true;
    // }
    // return false;
}

int sherlockAndAnagrams(string s)
{
    int result = 0;
    vector<string> substrings;
    int lenStrIn = s.length();

    // cắt chuỗi ?
    // ifailuhkqq
    // -> i, if, ifa, ipas, ... ifailuhkqq
    // -> f, fa, fai, pass, ... ifailuhkqq
    for (int i = 0; i < lenStrIn; i++) // i: position
    {
        // j đóng vai len (chiều dài chuỗi cần cắt)
        for (int j = 1; j <= lenStrIn - i; j++)
        {
            // Function: string substr (size_t pos, size_t len);
            // cắt chuỗi with i,j index -> push vào trong vector
            // -> vector sẽ có SIZE: n*(n-1)/2 = n + (n-1) + (n-2) +... + 1
            substrings.push_back(s.substr(i, j)); // i: start index, j: end index
        }
    }
    /**
     * Từ 1 chuỗi, so sánh với tất cả các chuỗi còn lại, của mảng
     */
    // duyệt qua tất cả các substring vừa mới cắt ra từ chuỗi gốc: ( lenStrIn * ( lenStrIn - 1 ) / 2 )
    int numOfSubstrings = substrings.size();
    for (int i = 0; i < numOfSubstrings; i++)
    {
        for (int j = i + 1; j < numOfSubstrings; j++)
        {
            // 1. Điều kiện tiên quyết để so sánh: hai chuỗi có độ dài bằng nhau.
            // 2. isAnagram: hai cái cần đối xứng.
            if (substrings[i].length() == substrings[j].length() && isAnagram(substrings[i], substrings[j]))
            {
                result++;
            }
        }
    }
    return result;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        cout << result << "\n";
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
