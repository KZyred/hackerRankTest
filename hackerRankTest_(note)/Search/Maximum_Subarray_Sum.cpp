#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

// long maximumSum(vector<long> a, long m)
// {
// }
long maxSum(vector<long> a, long m)
{
    long sum = 0, max = LONG_MIN, result = LONG_MAX;
    set<long> s;

    for (int i = 0; i < a.size(); i++)
    {
        sum = (sum + a[i]) % m;
        a[i] = sum;
        max = std::max(max, sum);
    }

    for (auto x : a)
    {
        auto p = s.insert(x);
        if (++p.first != s.end())
        {
            result = min(*p.first - x, result);
        }
    }

    return std::max(max, m - result);
}

int main()
{
    int query;
    cin >> query;
    while (query--)
    {
        int n;
        long m;
        vector<long> arr;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            long item;
            cin >> item;
            arr.push_back(item);
        }

        cout << maxSum(arr, m) << endl;
    }

    return 0;
}
