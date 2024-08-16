
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<string> split_string(string);

long minTime(vector<long> machines, long goal)
{
    // 1. find max
    long maxVal = INT_MIN;
    for (auto i : machines)
    {
        maxVal = max(maxVal, i);
    }
    // 2. find day
    long low = 1;
    long high = maxVal * goal;
    // long mid = 0;

    while (low < high)
    {
        long items = 0;
        long mid = (high + low) >> 1;
        for (auto i : machines)
        {
            items += mid / i;
        }
        if (items < goal)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}

int main()
{
    long n, goal;
    cin >> n >> goal;
    vector<long> machines;
    for (int i = 0; i < n; i++)
    {
        long machine;
        cin >> machine;
        machines.push_back(machine);
    }
    long ans = minTime(machines, goal);
    cout << ans << "\n";
    return 0;
}
