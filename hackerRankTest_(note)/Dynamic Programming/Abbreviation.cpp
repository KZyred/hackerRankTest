// /**
//  * Yêu cầu:
//     * - Cho hai string a, b
//     *   + a: string to modify - gồm cả kí tự viết hoa + thường, ascii[A-Za-z].
//     *   + b: string to match  - chỉ bao gồm viết hoa, ascii[A-Z].
//     * - Xác định xem a có thể chuyển thành b được không, được sử dụng các hành động sau:
//         + Có thể viết hoa 0 hoặc nhiều chữ cái viết thường của a.
//         + Chỉ được xóa các chữ cái viết thường của a (chữ hoa ko được)

//  * Test Case:
//         1
//         daBcd
//         ABC
//     -> out: YES

//  *  Ý tưởng:
// 1.
/**
 * hai chuỗi :
 *         daBcd
 *         ABC
 * -> ta đánh giá từ đuôi
 * 1. d và C khác nhau -> daBc vs ABC
 * 2. c và C -> hai trường hợp: daB vs AB or daB vs ABC   -> chú ý: dùng or, do là boolean
 *
 * ... lặp lại cho tới khi
 * 1. a non-empty và b empty: f(a,b) True -> chỉ nếu tất cả kí tự trong a là lower-case
 * 2. a empty và b non-empty: khi f(a,b) False
 * 3. a,b empty : f(a,b) True
 */
// -> Tuy nhiên không giải quyết được đề bài: do, yêu cầu không được xóa các upper-case trong a nếu không trùng lặp
//
// 2.
//
//  *
//  *  Nhận xét ý tưởng:
//  *  - Ý tưởng: ý tưởng hay, dễ hiểu
//  */

// #include <iostream>
// #include <string>
// #include <ctype.h>

// using namespace std;

// string abbreviation(string a, string b)
// {
//     return a;
// }

// int main()
// {
//     int q;
//     cin >> q;
//     cin.ignore();
//     for (int q_itr = 0; q_itr < q; q_itr++)
//     {
//         string a;
//         getline(cin, a);

//         string b;
//         getline(cin, b);

//         string res = abbreviation(a, b);
//         cout << res << endl;
//     }

//     return 0;
// }

/**
 * A, B
 * dp[i, j] = 1, nếu first char A có thể chuyển đổi được về first char B
 * else dp[i, j] = 0;
 *
 * Có 3 điều kiện khác nhau để xem xét:
    1.1 Nếu có một chữ IN HOA ở vị trí i+1 trong A và chúng ta đã xét j ký tự trong B
    thì nếu ký tự thứ (i+1) của A bằng ký tự thứ (j+1) của B
    , ký tự thứ (i+1) sẽ được đặt ở vị trí thứ (j+1) trong B.
        -> dp[i+1, j+1] = 1

    1.2 Nếu có một chữ cái viết thường ở vị trí i+1 trong A thì nó có thể được đặt ở vị trí j+1 trong B
    nếu ký tự thứ (j+1) là chữ hoa tương đương với ký tự i+1 trong A.
        -> dp[i+1, j+1] = 1

    2. Nếu có chữ thường ở vị trí i+1 trong A thì không dùng được trong B vì B chỉ có chữ in hoa.
        -> dp[i+1, j] = 1
    điều đó có nghĩa là j ký tự của B có thể được hình thành bằng cách sử dụng ký tự i + 1 đầu tiên của A.


Vì vậy, sau khi tìm kiếm tất cả các trạng thái, các trạng thái có thể đạt được sẽ được đánh dấu là 1.

Câu trả lời là "YES", nếu "ký tự cuối cùng" của A tồn tại cách chuyển đổi nó thành ký tự cuối cùng của B.
 */

#include <iostream>
#include <string>
using namespace std;

bool isUpcase(char c)
{
    return (c >= 'A') && (c <= 'Z');
}

char upcase(char c)
{
    if (isUpcase(c))
        return c;
    return (char)(c - 32);
}

bool dp[1011][1011]; // tại sao? -> do đề bài cho ( 1 <= |a| <= |b| <= 1000 )

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        string a_ar, b_ar;
        cin >> a_ar;
        cin >> b_ar;

        int a = a_ar.length();
        int b = b_ar.length();

        // 1. Tạo ma trận, a hàng, b cột
        for (int i = 0; i <= a; i++)
        {
            for (int j = 0; j <= b; j++)
            {
                dp[i][j] = false;
            }
        }

        // 2. Khởi tạo [0, 0] là TRUE
        dp[0][0] = true;

        // 3.
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j <= b; j++)
            {
                if (dp[i][j])
                {
                    // 1.1 j nằm trong phạm vi mảng b, kí tự trong mảng a (up hoặc ko) == mảng b
                    if (j < b && (upcase(a_ar[i]) == b_ar[j]))
                    {
                        dp[i + 1][j + 1] = true; // chéo = true (trong ô vuông  2 X 2)
                    }
                    // 1.2 Check trong a, có viết hoa hay không ?!
                    // Nếu đang không viết hoa
                    if (!isUpcase(a_ar[i]))
                    {
                        dp[i + 1][j] = true; // hàng ngay phía dưới (2 X 2)
                    }
                }
            }
        }

        // 04. Phần tử chéo cuối cùng của mảng phải là 1 -> Mới thỏa mãn
        if (dp[a_ar.length()][b_ar.length()])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// Có thể hiểu tại sao lại là ma trận như sau:
/**
1. Mẫu thử:
    1
    daBcd
    ABC

2. Ta được ma trận:
Trước:
  A B C (j)
d 1 0 0 0
a 0 0 0 0
B 0 0 0 0
c 0 0 0 0
d 0 0 0 0
  0 0 0 0
(i)

Sau:
  A B C
d 1 0 0 0
a 1 0 0 0
B 1 1 0 0
c 0 0 1 0
d 0 0 1 1
  0 0 1 1



 */
