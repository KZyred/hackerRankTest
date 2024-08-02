// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// int main()
// {
//     int n; // chiều dài chuỗi
//     int ans = 0;

//     cin >> n;
//     string s;
//     cin >> s;

//     /**
//      * Có các điểm đặc biệt lưu ý ở dự án này:
//      * 1. mảng same_char_count lưu trữ lượng kí tự giống nhau:
//      *    - ví dụ: aaaabbcc -> 4 0 0 0 2 0 1 1 1
//      * 2.
//      */
//     int same_char_count[s.length()] = {0}; // đây là mấu chốt

//     /**
//      * Vòng 1.
//      * - Tìm tất cả các trường hợp kí tự giống nhau, liền kề nhau hoặc đơn lẻ
//      * - Mảng số lượng các kí tự liền nhau
//      *
//      */
//     int c;     // biến count cho công thức K*(K+1)/2, vòng 1
//     int i = 0; // index cho lần duyệt, vòng 1
//     int j;     // index tiếp tục

//     while (i < n) // do các index đều không xác định trước nên không dùng for
//     {
//         j = i + 1;                    // cho chỉ số liền kề
//         c = 1;                        //
//         while (j < n && s[i] == s[j]) // duyệt qua các phần tử còn lại, thấy trùng + liền kề
//         {                             //
//             j++;                      // tăng lên để check trùng cái kế tiếp
//             c++;                      // cho công thức K*(K+1)/2, với các phần tử liền kề
//         }

//         // Lượng các substring có cùng các kí tự giống liền kề nhau
//         // Nếu có số các kí tự liền kề -> số lượng các substring tạo ra được tự đống liền kề này (hay)
//         // Ta dựa vào công thức: K*(K+1)/2
//         ans += (c * (c + 1)) / 2; // tất cả lượng substring
//         same_char_count[i] = c;   // lượng kí tự sẽ được lưu ở thằng đầu tiên ()
//         i = j;                    // tăng lên với các char tiếp theo, (kể cả các kí tự đơn)
//     }

//     /**
//      * Vòng 2.
//      * -
//      */
//     for (int k = 1; k < n - 1; k++) // 1 và n-1, do dưới check trước và sau
//     {
//         /**
//          * 2.1 điền đầy mảng same_char_count
//          * ví dụ: aaaabbcbc -> 4 0 0 0 2 0 1 1 1
//          * -> 4 4 4 4 2 2 1 1 1
//          */
//         if (s[k] == s[k - 1]) // kí tự trước giống kí tự sau
//         {
//             same_char_count[k] = same_char_count[k - 1]; // thay đổi mảng trước giống mảng sau
//         }

//         // các substr(s) có độ dài lẻ có phần tử ở "giữa khác nhau"
//         // ví dụ: aaaabbcbc -> 4 0 0 0 2 0 1 1 1
//         // -> 4 4 4 4 2 2 1 1 1
//         if (s[k - 1] == s[k + 1] && s[k] != s[k - 1])                   // trường hợp đối xứng 3: ví dụ: aba
//         {                                                               //
//             ans += min(same_char_count[k - 1], same_char_count[k + 1]); // lấy nhỏ nhất do có thể gặp trường hợp đối xứng 2 bên
//             // ??? câu hỏi đặt ra là sao ko +1 mà lại cần làm như vậy // thực nhiệm với test case cho thấy, ko dùng được +1
//         }
//     }
//     cout << ans << endl;

//     return 0;
// }

/**
Giải thích chi tiết:
Mẹo để giải quyết vấn đề này là tìm tất cả các chuỗi con cho mỗi trường hợp trong hai trường hợp.

Trường hợp 1: Tất cả các ký tự đều giống nhau.
    - Công thức: Đối với một chuỗi có n ký tự, chúng ta có thể tạo tổng cộng n*(n+1)/2 chuỗi con.
    Lưu ý các chuỗi con giữ nguyên thứ tự và không bỏ qua ký tự.
    - Ví dụ, aaaa sẽ tạo ra a, a, a, a, aa, aa, aa, aaa, aaa và aaaa
    - Giải thích:
        Điều này là do đối với một chuỗi có kích thước n,
        có thể tạo n chuỗi con có kích thước 1
        n - 1 chuỗi con có kích thước 2
        và  n - 2 chuỗi con có kích thước 3, v.v.
    Điều này có thể được khái quát thành n-(k-1)
    trong đó k là độ dài của chuỗi con.
    - Vì vậy, tổng số chuỗi con (của tất cả các độ dài) khi đó là n-1 + n-2 + ... + n - (k-1) + ... + n - (n-1).
    -> Khi viết ngược lại, điều này giống như 1 + 2 + ... + n-2 + n-1 + n.
    -> Tổng của một dãy số học là = n*(first+last)/2. Do đó, tổng của dãy trên là n*(1+n)/2



Trường hợp 2: Chuỗi có độ dài lẻ với tất cả các ký tự giống nhau ngoại trừ ký tự ở giữa

    - Quan sát: Đối với một chuỗi như aaabaaa, tổng số chuỗi con đặc biệt bằng với số ký tự lặp lại.
    - Ví dụ: là aba, aabaa, aaabaaa.

    Vì vậy, khi chúng ta tìm thấy một ký tự, c,
    sao cho ký tự trước đó của nó, giả sử: pc,
    giống với ký tự tiếp theo của nó, giả sử: nc,
    tức là pc == nc nhưng không giống với chính nó,
    tức là pc != c (tương tự việc nc != c),
    chúng ta có thể đếm số lần pc và nc được lặp lại.

    Lưu ý rằng, số lần pc được lặp lại có thể khác với số lần nc được lặp lại,
    ví dụ aaabaa. -> 333122 -> MIN(3, 2) = 2 -> 2 lần gặp gương là aabaa và aba.
    Chúng ta lấy GIÁ TRỊ NHỎ NHẤT trong số các lần lặp lại.

    - Vận dụng: Để tăng hiệu quả, chúng ta có thể tạo một mảng lưu trữ số lần một ký tự được lặp lại tại mọi chỉ mục.
    Ví dụ, đối với một chuỗi như aaabaa, mảng sẽ chứa 333122
 */

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long substrCount(int n, string s)
{
    int result = 0;
    int iStr = 0;
    int cntArrChar[n] = {0};
    while (iStr < n)
    {
        int j = iStr + 1;
        int c = 1;
        while (j < n && s[iStr] == s[j])
        {
            j++;
            c++;
        }
        result += (c + 1) * c / 2;
        cntArrChar[iStr] = c;
        iStr = j;
    }
    for (int k = 1; k < n - 1; k++)
    {
        if (s[k] == s[k - 1])
        {
            cntArrChar[k] = cntArrChar[k - 1];
        }
        if (s[k + 1] == s[k - 1] && s[k - 1] != s[k])
        {
            result += min(cntArrChar[k + 1], cntArrChar[k - 1]);
        }
    }
    return result;
}

int main()
{

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    cout << result << "\n";

    return 0;
}
