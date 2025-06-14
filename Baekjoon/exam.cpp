// A - 장난감 경주
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int N, int X, int Y, double my_v, double others_t)
{
    double my_t_no_boost = (double)X / my_v;
    if (my_t_no_boost < others_t)
    {
        cout << 0 << '\n';
        return;
    }
    if ((X - Y) / my_v + 1 >= others_t)
    {
        cout << -1 << '\n';
        return;
    }

    int left = 1;
    int right = Y;
    int mid = (1 + Y) / 2;

    while (left <= right)
    {
        double BoosterTime = ((double)(X - mid) / my_v) + 1;
        if (BoosterTime >= others_t)
            left = mid + 1;
        else
            right = mid - 1;
        mid = (left + right) / 2;
    }

    cout << mid + 1 << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N, X, Y;
        cin >> N >> X >> Y;
        vector<int> V(N);
        double others_t = 1e18;
        for (int i = 0; i < N; ++i)
        {
            cin >> V[i];
            if (i != (N - 1))
            {
                double t = (double)X / V[i];
                others_t = min(others_t, t);
            }
        }
        double my_v = V[N - 1];
        solve(N, X, Y, my_v, others_t);
    }
    return 0;
}
