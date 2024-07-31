#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n; // chiều dài chuỗi
    int ans = 0;

    cin >> n;
    string s;
    cin >> s;

    int same_char_count[n] = {0};

    /**
     * Vòng 1. Tìm tất cả các trường hợp kí tự giống nhau, liền kề nhau hoặc đơn lẻ
     */
    int c;     // biến count cho công thức K*(K+1)/2, vòng 1
    int i = 0; // index cho lần duyệt, vòng 1
    int j;     // index tiếp tục

    for (int i = 0; i < n; i++)
    {
        c = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                c++;
            }
            else
            {
                break;
            }
            i = j; // tăng lên với các char tiếp theo, (kể cả các kí tự đơn)
        }
        ans += (c * (c + 1)) / 2;
        same_char_count[i] = c;
    }
    // while (i < n)
    // {
    //     j = i + 1; // cho chỉ số liền kề
    //     c = 1;
    //     while (j < n && s[i] == s[j]) // thấy trùng liền kề
    //     {
    //         ++j; // tăng lên để check trùng cái kế tiếp
    //         ++c;
    //     }

    //     // Lượng các substring có cùng các kí tự giống liền kề nhau
    //     // Nếu có số các kí tự liền kề -> số lượng các substring tạo ra được tự đống liền kề này (hay)
    //     // Ta dựa vào công thức: K*(K+1)/2
    //     ans += (c * (c + 1)) / 2;
    //     same_char_count[i] = c;
    //     i = j; // tăng lên với các char tiếp theo, (kể cả các kí tự đơn)
    // }

    for (int k = 1; k < n - 1; ++k)
    {
        if (s[k] == s[k - 1])
        {
            same_char_count[k] = same_char_count[k - 1];
        }

        // odd length substr(s) which has middle element diiferent
        if (s[k - 1] == s[k + 1] && s[k] != s[k - 1])
        {
            ans += min(same_char_count[k - 1], same_char_count[k + 1]);
        }
    }
    cout << ans << endl;

    return 0;
}