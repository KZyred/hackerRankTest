/**
 * Yêu cầu:
 * - Cho n phần tử
 *  + Đứa nào cũng được nhận tối thiểu 1 viên kẹo
 *  + cứ hai đứa kề nhau, có 1 đứa lớn hơn thì được, nhận số kẹo = số kẹo người bé hơn + 1
 * Trả về:
    - lượng kẹo tối thiểu tối thiểu, phải mua

 a b c
 1 1 1

 a < b > c -> 1 b+1 1
 a > b < c -> a+1 1 2



 * Test Case:
        3 - length
        1
        2
        2
    -> out: 4

    10
    2 4 2 6 1 7 8 9 2 1
    1 2 1 2 1 2 3 4 2 1

    1 2 1 2 1 2 3 4 1 1
    1 2 1 2 1 1 1 3 2 1

    -> out 19

    8
    2 4 3 5 2 6 4 5
    1 2 1 2 1 2 1 2
    -> out 12

 *  Ý tưởng:
        1. Duyệt qua hai lần mảng
          + duyệt từ trái -> phải + (i < i+1) -> cộng dồn
          + duyệt từ phải -> trái + (i > i+1) -> cộng dồn
        -> lấy max với từng index
        -> đưa ra tổng
 *
 *  Nhận xét ý tưởng:
 *  - Ý tưởng: ý tưởng hay, dễ hiểu
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long candies(int n, vector<int> arr)
{
    vector<int> minL2R(n, 1);
    vector<int> minR2L(n, 1);
    long res = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] < arr[i])
        {
            minL2R[i] = minL2R[i - 1] + 1;
        }
    }
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            minR2L[i] = minR2L[i + 1] + 1;
        }
    }
    for (int i = 0; i < minL2R.size(); i++)
    {
        res += max(minL2R[i], minR2L[i]);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> ratArr(n);
    for (auto &i : ratArr)
    {
        cin >> i;
    }

    long result = candies(n, ratArr);
    cout << result << "\n";

    return 0;
}
