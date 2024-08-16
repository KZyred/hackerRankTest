/**
 * Yêu cầu:
    * - Cho n phần tử
    * - Tìm ra các mảng con thỏa mãn:
    *   1. Các phần tử trong mảng con không liền kề (trong mảng ban đầu).
    *   2. Mảng con phải có ít nhất 2 phần tử
    *   3. Tổng các phần tử trong mảng con là lớn nhất.

 * Test Case:
        5
        3 7 4 6 5
    -> out: 13 (mảng con [7, 6])

 *  Ý tưởng:
        1. Thuần vét cạn, yêu cầu phải sinh ra tất cả các mảng con (thỏa mãn)
            -> O(2^n)
        2. quy hoạch động:
        sở dĩ sử dụng là do nhận thấy có nhiều hơn 1 lần lặp lại tính tổng của mảng con trước đó
        -> áp dụng quy hoạch động
 *
 *  Nhận xét ý tưởng:
 *  - Ý tưởng: ý tưởng hay, dễ hiểu
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Cứ hiểu như cách đọc code bình thường
// Chú ý:
//  1. Duyệt từ cuối lên (code ngắn hơn, dễ hơn duyệt từ đầu xuống)
// => câu hỏi đặt ra:
// tại sao ko so sánh "arr[i] + sumed[i + 2] và sumed[i + 2]" , mà lại là sumed[i + 1])

// Suy nghĩ: nếu không so sánh với sumed[i + 1]) thì không có sự kế thừa max liên tiếp tới đầu mảng
// dùng sumed[i + 2]) chỉ đem lại hiệu năng theo định nghĩa mảng
int maxSubsetSum(vector<int> arr)
{
    //  2. arr.size() + 2: +2 do bên dưới sử dụng: sumed[i + 2], nghĩa là cần mượn thêm 2 phần tử ngoài mảng
    vector<int> sumed(arr.size() + 2, 0);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        sumed[i] = std::max(arr[i] + sumed[i + 2], sumed[i + 1]); // sở dĩ: có sumed[i + 1] là tạo thế duy trì max đẩy về phần tử số 0
        // 1. arr[i] + sumed[i + 2]: do yêu cầu để bài, (mảng không phải là hai phần tử liên tiếp)
        //      (nếu ko có yêu cầu trên, chỉ cần std::max(arr[i] + sumed[i + 1], sumed[i + 1]))
        // 2. sumed[i + 1]: phục vụ, đảm bảo max luôn được xem xét, và đẩy lên đầu mảng
    }
    return sumed[0];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }

    int res = maxSubsetSum(arr);

    cout << res << "\n";

    return 0;
}