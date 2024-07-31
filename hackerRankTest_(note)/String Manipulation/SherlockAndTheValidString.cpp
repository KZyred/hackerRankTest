#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 *
 *
 *
 * Cách này cần có kiến thức về unorder_map
 *
 * đầu vào: string
 * string đạt yêu cầu khi số lần xuất hiện là giống nhau
 * ngoài ra có thể remove 1 nếu ở chỉ 1 chỉ mục thừa
 */

string isValid(string s)
{
    unordered_map<char, int> tmChar;
    for (int i = 0; i < s.length(); i++)
    {
        auto got = tmChar.find(s[i]);
        if (got == tmChar.end())
            tmChar.insert({s[i], 1});
        else
            tmChar.at(s[i]) += 1;
    }
    int checkT = tmChar.at(s[0]);
    int times = 0;
    for (auto &it : tmChar)
    {
        int c = abs(it.second - checkT);
        if (c >= 1)
        {
            times++;
        }
        if (times > 1)
        {
            return "NO";
        }
    }
    return "YES";
}

int main()
{
    string s;
    getline(cin, s);

    string result = isValid(s);

    cout << result << "\n";
    return 0;
}
