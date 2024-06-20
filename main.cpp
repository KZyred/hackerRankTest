#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

/**
 * 1,2,3,5,4,6,7,8
 * -> 1,2,3,5,4,6,7,8 (nếu người 5 hối lộ người 4)
 * -> print 1
 *
 * 1,2,3,4,5
 * 2,5,1,3,4
 *
 *
 * 4,5,3,2,1
 *
 * người 4 phải hối lộ 3 người còn lại
 * -> nếu người nào đó hối lộ nhiều hơn 2
 * -> Too chaotic
 *
 */

// 1 2 5 3 7 8 6 4

// 1 2 3 4 5 6 7 8
void minimumBribes(vector<int> q)
{
    // init 1 2 3 4 5
    // -> làm sao để mảng trở thành 2,1,5,3,4

    // 1 2 3 4 5 -> 1 2 3 5 4 -> 1 2 5 3 4 -> 2 1 5 3 4
    // => in ra 3
    int cnt = 0;
    int i = 1;
    while (i <= q.size())
    {
        if (i < q.size() && (q[i - 1] + q[i]) == (i + i + 1))
        {
            i += 2;
            cnt++;
        }
        if ((i + 1) < q.size() && (q[i - 1] + q[i] + q[i + 1]) == (i + i + 1 + i + 2) && (q[i - 1] == i || q[i - 1] == i + 1))
        {
            i += 3;
            cnt += 2;
        }
        if (q[i - 1] == i)
            cnt = 0;
        i++;
    }
    if (cnt == 0)
    {
        cout << "Too chaotic" << endl;
        return;
    }
    cout << cnt << endl;
}
// 1 2 3 4 5 6 7 8

// 1 2 3 4 5 6 8 7
// 1 2 3 4 5 8 6 7

// 1 2 5 3 7 8 6 4
// 1 2 4

// nên nhớ người trước hối lộ người sau
void calc(vector<int> q)
{
    int ans = 0;
    for (int i = q.size() - 1; i >= 0; i--)
    {
        if (q[i] - (i + 1) > 2)
        {
            cout << "Too chaotic" << endl;
            return;
        }
        for (int j = max(0, q[i] - 2); j < i; j++)
            if (q[j] > q[i])
                ans++;
    }
    cout << ans << endl;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++)
        {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        calc(q);
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
