#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 1024

int l[MAXN + 1]; // mảng lưu trữ left childrent
int r[MAXN + 1]; // mảng lưu trữ rights childrent
int d[MAXN + 1]; // mảng chiều sâu của cây tương ứng với các cấp độ node
int n;           // số phần tử của cây
int t;           // số lần query
int k;           // k, bội ứng với mỗi lần query

// tính toán độ sâu của nút hiện tại và mọi nút con bên dưới nó.
void calc_depth(int cur, int depth)
{
    d[cur] = depth;
    if (l[cur] > 0)
        calc_depth(l[cur], depth + 1);
    if (r[cur] > 0)
        calc_depth(r[cur], depth + 1);
}

// duyệt, in các phần tử của cây
void in_order(int cur)
{
    if (l[cur] > 0)
        in_order(l[cur]);
    cout << cur << " ";
    if (r[cur] > 0)
        in_order(r[cur]);
}

// Input is sample #02
int main()
{
    // I. dòng 1, số node trong tree
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i]; // các nhánh trái và phải
    }

    // tính toán death của từng node tương ứng độ sâu của chúng
    calc_depth(1, 1);

    cin >> t;
    while (t--)
    {
        cin >> k;
        for (int i = 1; i <= n; i++)
        {
            if (d[i] % k == 0)
            {
                // d[i] is a multiple of k
                // left child of i becomes right, and vice versa
                swap(l[i], r[i]);
            }
        }
        // print the answer
        in_order(1); // duyệt từ phần tử có index là 1
        cout << endl;
    }
    return 0;
}
