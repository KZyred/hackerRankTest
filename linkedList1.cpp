#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

bool isAnagram(string s1, string s2)
{
    const int charFreqLeth = 26;
    int charFreq[charFreqLeth] = {0};
    for (int i = 0; i < s1.length(); i++)
    {                            //
        charFreq[s1[i] - 'a']++; // adding 1 for every character of s1
        charFreq[s2[i] - 'a']--; // subtracting 1 for every character of s2
    }

    for (int i = 0; i < charFreqLeth; i++)
    { //
        if (charFreq[i] != 0)
            return false;
    }
    return true;
}

int sherlockAndAnagrams(string s)
{
    int count = 0;
    vector<string> substrings;

    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        for (int j = 1; j <= len - i; j++)
        {
            substrings.push_back(s.substr(i, j));
        }
    }

    int numOfSubstrings = substrings.size();
    for (int i = 0; i < numOfSubstrings; i++)
    {
        for (int j = i + 1; j < numOfSubstrings; j++)
        {
            if (substrings[i].length() == substrings[j].length() && isAnagram(substrings[i], substrings[j]))
            {
                count++;
            }
        }
    }

    return count;
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
