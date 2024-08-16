/**
 * Yêu cầu:
    - Cho 3 mảng với chiều dài lena, lenb, lenc
    - Tìm ra các mảng có 3 phần tử, p, q, r sao cho q >= p; q >= r;
    - chú ý các mảng có 3 phần tử không được phép trùng nhau.
 * Test Case:
        3 2 3
        1 3 5
        2 3
        1 2 3
    Output:
        1,2,1
        1,2,2
        1,3,1
        1,3,2
        1,3,3
        3,3,1
        3,3,2
        3,3,3

 *  Ý tưởng:
        1. Vét cạn, tìm với q tìm lượng phần tử nhỏ hơn q trong lena, và lenb -> nhân -> cộng -> kết quả cuối cùng
        - chủ ý các phần từ trong b có thể giống nhau -> cần lọc

 *  Nhận xét ý tưởng:
   - Ý tưởng:
 */
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<string> split_string(string);

long triplets(vector<int> a, vector<int> b, vector<int> c)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    int j = 0, k = 0;
    long result = 0;
    for (int i = 0; i < b.size(); i++)
    {
        while (a[j] <= b[i] && j < a.size())
            j++;
        while (c[k] <= b[i] && k < c.size())
            k++;
        result += (long)j * k;
    }
    return result;
}

int main()
{
    string lenaLenbLenc_temp;
    getline(cin, lenaLenbLenc_temp);

    vector<string> lenaLenbLenc = split_string(lenaLenbLenc_temp);

    int lena = stoi(lenaLenbLenc[0]);

    int lenb = stoi(lenaLenbLenc[1]);

    int lenc = stoi(lenaLenbLenc[2]);

    string arra_temp_temp;
    getline(cin, arra_temp_temp);

    vector<string> arra_temp = split_string(arra_temp_temp);

    vector<int> arra(lena);

    for (int i = 0; i < lena; i++)
    {
        int arra_item = stoi(arra_temp[i]);

        arra[i] = arra_item;
    }

    string arrb_temp_temp;
    getline(cin, arrb_temp_temp);

    vector<string> arrb_temp = split_string(arrb_temp_temp);

    vector<int> arrb(lenb);

    for (int i = 0; i < lenb; i++)
    {
        int arrb_item = stoi(arrb_temp[i]);

        arrb[i] = arrb_item;
    }

    string arrc_temp_temp;
    getline(cin, arrc_temp_temp);

    vector<string> arrc_temp = split_string(arrc_temp_temp);

    vector<int> arrc(lenc);

    for (int i = 0; i < lenc; i++)
    {
        int arrc_item = stoi(arrc_temp[i]);

        arrc[i] = arrc_item;
    }

    long ans = triplets(arra, arrb, arrc);

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
