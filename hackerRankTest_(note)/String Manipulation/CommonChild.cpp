/**
Có rất nhiều cách làm: https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
1. Tôi sử dụng cách dùng bảng tính dễ hình dung hơn:

Nhận xét:
  1. Tạo ma trận trong C++
  - Thường thì số chiều phải là const.
  - Đã xác định trước.

  2. Bài toán này thuộc dạng Dynamic Programming (quy hoạch động).

  3. Dễ nhớ nhất thì hãy tưởng tượng:
  - Đặt dãy 1 theo cột dọc
  - Dãy 2 theo hàng ngang
  - Tạo ma trận (row = size of string 1; col = size of string 2)
  - Tưởng tượng: ma trận vuông 4:
        (i,j)   (i,j+1)
        (i+1,j) (i+1,j+1)
    + nếu kí tự giống nhau: (i+1,j+1) = (i,j) ++;
    + nếu kí tự khác:       (i+1,j+1) = max((i,j+1), (i+1,j));
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[7][7];
// Chú ý riêng C++, không có tạo được kiểu mảng khai báo với phần tử không được thông báo trước
// Ví dụ: dp[a.size()+1][b.size()+1] --> điều này gây lỗi

int main()
{
  string a, b;
  cin >> a >> b;

  int rows = sizeof(dp) / sizeof(dp[0]);
  int cols = sizeof(dp[0]) / sizeof(dp[0][0]);
  cout << "rows : " << rows << " cols : " << cols << endl;

  for (int i = 0; i < a.size(); i++)
  {
    for (int j = 0; j < b.size(); j++)
    {
      if (a[i] == b[j])
        dp[i + 1][j + 1] = dp[i][j] + 1;
      else
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    }
    // /**
    //  * in ra để hình dung rõ kết quả bị thay đổi
    //  */
    // cout << "a[i] : " << a[i] << endl;
    // cout << "  ";
    // for (int i = 0; i < b.size(); i++)
    // {
    //   cout << b[i] << " ";
    // }
    // cout << endl;

    // for (int i = 0; i < rows; i++)
    // {
    //   if (i < a.size())
    //   {
    //     cout << a[i] << " ";
    //   }
    //   else
    //   {
    //     cout << "  ";
    //   }
    //   for (int j = 0; j < cols; j++)
    //   {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
  }

  cout << dp[a.size()][b.size()]; // in ra phần tử cuối cùng của ma trận

  return 0;
}

/**
- Một cái nhìn sai, khi đặt hàng và cột nhầm
 the first string along the top and with the other string along the side. (nếu làm theo cái này sẽ nhất khó hiểu)
- Giải thích với:
    ABCDEF
    FBDAMN

a[i] : A
  A B C D E F
F 0 0 0 0 0 0 0
B 0 0 0 0 1 1 1
D 0 0 0 0 0 0 0
A 0 0 0 0 0 0 0
M 0 0 0 0 0 0 0
N 0 0 0 0 0 0 0
  0 0 0 0 0 0 0

a[i] : B
  A B C D E F
F 0 0 0 0 0 0 0
B 0 0 0 0 1 1 1
D 0 0 1 1 1 1 1
A 0 0 0 0 0 0 0
M 0 0 0 0 0 0 0
N 0 0 0 0 0 0 0
  0 0 0 0 0 0 0

a[i] : C
  A B C D E F
F 0 0 0 0 0 0 0
B 0 0 0 0 1 1 1
D 0 0 1 1 1 1 1
A 0 0 1 1 1 1 1
M 0 0 0 0 0 0 0
N 0 0 0 0 0 0 0
  0 0 0 0 0 0 0

a[i] : D
  A B C D E F
F 0 0 0 0 0 0 0
B 0 0 0 0 1 1 1
D 0 0 1 1 1 1 1
A 0 0 1 1 1 1 1
M 0 0 1 2 2 2 2
N 0 0 0 0 0 0 0
  0 0 0 0 0 0 0

a[i] : E
  A B C D E F
F 0 0 0 0 0 0 0
B 0 0 0 0 1 1 1
D 0 0 1 1 1 1 1
A 0 0 1 1 1 1 1
M 0 0 1 2 2 2 2
N 0 0 1 2 2 2 2
  0 0 0 0 0 0 0

a[i] : F
  A B C D E F
F 0 0 0 0 0 0 0
B 0 0 0 0 1 1 1
D 0 0 1 1 1 1 1
A 0 0 1 1 1 1 1
M 0 0 1 2 2 2 2
N 0 0 1 2 2 2 2
  0 1 1 2 2 2 2

 */

/**
 * Đây là mới thì giác nhìn đúng, dễ hiểu
- Do ta tưởng ABCDEF là duyệt qua cột, hàng như trên
- Nhưng nhìn kiểu này sẽ song song với ma trận, từ đó dễ nhìn hơn



a[i] : A
  F B D A M N
A 0 0 0 O 0 0 0
B 0 0 0 0 I 1 1
C 0 0 0 0 0 0 0
D 0 0 0 0 0 0 0
E 0 0 0 0 0 0 0
F 0 0 0 0 0 0 0
  0 0 0 0 0 0 0

a[i] : B
  F B D A M N
A 0 0 0 0 0 0 0
B 0 0 0 0 1 1 1
C 0 0 1 1 1 1 1
D 0 0 0 0 0 0 0
E 0 0 0 0 0 0 0
F 0 0 0 0 0 0 0
  0 0 0 0 0 0 0

a[i] : C
  F B D A M N
A 0 0 0 0 0 0 0
B 0 0 0 0 1 1 1
C 0 0 1 1 1 1 1
D 0 0 1 1 1 1 1
E 0 0 0 0 0 0 0
F 0 0 0 0 0 0 0
  0 0 0 0 0 0 0

a[i] : D
  F B D A M N
A 0 0 0 0 0 0 0
B 0 0 0 0 1 1 1
C 0 0 1 1 1 1 1
D 0 0 1 1 1 1 1
E 0 0 1 2 2 2 2
F 0 0 0 0 0 0 0
  0 0 0 0 0 0 0

a[i] : E
  F B D A M N
A 0 0 0 0 0 0 0
B 0 0 0 0 1 1 1
C 0 0 1 1 1 1 1
D 0 0 1 1 1 1 1
E 0 0 1 2 2 2 2
F 0 0 1 2 2 2 2
  0 0 0 0 0 0 0

a[i] : F
  F B D A M N
A 0 0 0 0 0 0 0
B 0 0 0 0 1 1 1
C 0 0 1 1 1 1 1
D 0 0 1 1 1 1 1
E 0 0 1 2 2 2 2
F 0 0 1 2 2 2 2
  0 1 1 2 2 2 2



 */
