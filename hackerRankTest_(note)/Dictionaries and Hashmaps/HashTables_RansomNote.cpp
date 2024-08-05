#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'checkMagazine' function below.
 *
 * The function accepts following parameters:
 *  1. STRING_ARRAY magazine
 *  2. STRING_ARRAY note
 */

// kiểm tra trùng khớp giữa các từ trong note và magazine
// nếu các từ trong note đều có trong magazine thì thỏa mãn
// so sánh cụm từ -> str1.compare(str2)

/**
- Giải thích:
 + words[it]: là một cách lấy giá trị cũng như tạo nhanh giá trị.
 + Hỏi:
    tại sao đoạn "words[it]++;" words chưa có mà đã ++ được rồi
    tại sao words[it] mặc định ban đầu bằng 0

    Lý do:
    - nếu không có key bất kì thuộc unorder_map thì phần tử mới sẽ được tạo.
    Trình cấp phát mặc định sẽ gọi defualt contructor, và default constructor trả về 0

    - Nếu không tin tưởng về suy nghĩ trên thì hãy check tồn tại trong unorder_map không rồi insert hoặc update
 */

void checkMagazine(vector<string> magazine, vector<string> note)
{
    unordered_map<string, int> words;
    for (auto &it : magazine)
    {
        words[it]++; // được tạo nếu chưa có, mặc định là 0
    }
    for (auto &it : note)
    {
        if (words[it] > 0)
        {
            words[it]--; // rất hay đoạn này
        }
        else
        {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split(rtrim(magazine_temp_temp));

    vector<string> magazine(m);

    for (int i = 0; i < m; i++)
    {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split(rtrim(note_temp_temp));

    vector<string> note(n);

    for (int i = 0; i < n; i++)
    {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    checkMagazine(magazine, note);

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
