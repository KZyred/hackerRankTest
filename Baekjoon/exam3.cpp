// C - 좋은 노드 집합 찾기
// D - 등산로
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    int T;
    cin >> T;
    vector<ll> results;
    while (T--)
    {
        int n;
        cin >> n;
        vector<ll> val(n);
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }

        vector<int> p(n);
        vector<vector<int>> children(n);
        int root = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            if (p[i] == 0)
                root = i;
            else
                children[p[i] - 1].push_back(i);
        }

        // dp0[u], dp1[u]
        vector<ll> dp0(n, 0), dp1(n, 0);

        // iterative post-order traversal
        vector<pair<int, bool>> stk;
        stk.reserve(n * 2);
        stk.emplace_back(root, false);

        while (!stk.empty())
        {
            auto [u, seen] = stk.back();
            stk.pop_back();

            if (!seen)
            {
                // trước khi xử lý con
                stk.emplace_back(u, true);
                for (int v : children[u])
                {
                    stk.emplace_back(v, false);
                }
            }
            else
            {
                // sau khi xử lý con → compute dp[u]
                // dp1[u] = val[u] + sum(dp0[v])
                ll sum_dp0 = 0;
                for (int v : children[u])
                {
                    sum_dp0 += dp0[v];
                }
                dp1[u] = val[u] + sum_dp0;

                // dp0[u]: tổng max(dp0,dp1) cho con,
                // nếu không con nào dp1>dp0, thì trừ đi tổn thất nhỏ nhất
                ll total = 0;
                bool any_better = false;
                ll best_loss = LLONG_MAX; // dp0[v] - dp1[v]

                for (int v : children[u])
                {
                    ll take = dp1[v], skip = dp0[v];
                    if (take > skip)
                    {
                        any_better = true;
                        total += take;
                    }
                    else
                    {
                        total += skip;
                        best_loss = min(best_loss, skip - take);
                    }
                }

                if (children[u].empty())
                {
                    // lá: được phép không chọn con
                    dp0[u] = 0;
                }
                else if (any_better)
                {
                    dp0[u] = total;
                }
                else
                {
                    // bắt buộc chọn 1 con, tổng = sum(skip) - loss_min
                    dp0[u] = total - best_loss;
                }
            }
        }

        ll ans = max(dp0[root], dp1[root]);
        results.push_back(ans);
    }
    for (const auto &i : results)
        cout << i << "\n";
    return 0;
}
