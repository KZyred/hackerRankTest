/**
 * Yêu cầu:
    - Swapping:
        swap subtree có nghĩa là khi khởi tạo một node có left subtree là L và right subtree là R.
        Sau swap, left subtree là R, right subtree là L.
    - Cho số k, yêu cầu swap tất cả các node có độ sâu (depth) là bội của k

 * Test Case:
        3          - root node (luôn luôn bằng 1), cùng là số lượng phần tử trong node
        2 3        - các nút con
        -1 -1
        -1 -1
        2
        1
        1

    Output:
        3 1 2
        2 1 3

 *  Ý tưởng:
        1. Bài toàn không khó
            - Cần kiến thức cơ bản về biến đổi:
                + vector to tree
                + tree to vector
                + swap left
            1.1. Chuyển từ vector<vector> sang Tree
            1.2. Swap, Tree 2 vector

 *  Nhận xét ý tưởng:
   - Ý tưởng:
 */
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};
/**
 * Chuyển Tree thành Vector (mảng sắp xếp theo thứ tự inOrder)
 */
void inorder(Node *root, vector<int> &res_value)
{
    if (!root)
        return;
    inorder(root->left, res_value);
    res_value.push_back(root->data);
    inorder(root->right, res_value);
}
/**
 * Hoán đổi các giá trị của node
 */
void swapNodesUtil(Node *root, int level, int k)
{
    if (!root || (!root->left && !root->right))
        return;

    if (level % k == 0)
    {
        swap(root->left, root->right);
    }
    swapNodesUtil(root->left, level + 1, k);
    swapNodesUtil(root->right, level + 1, k);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{

    Node *root = new Node(1);

    queue<Node *> q;
    q.push(root);

    for (int i = 0; i < indexes.size(); i++)
    {

        Node *cur = q.front();
        q.pop();

        if (indexes[i][0] != -1)
        {
            cur->left = new Node(indexes[i][0]);
            q.push(cur->left);
        }

        if (indexes[i][1] != -1)
        {
            cur->right = new Node(indexes[i][1]);
            q.push(cur->right);
        }
    }

    vector<vector<int>> result;
    for (int i = 0; i < queries.size(); i++)
    {
        vector<int> res_value;
        swapNodesUtil(root, 1, queries[i]);
        inorder(root, res_value);
        result.push_back(res_value);
    }
    return result;
}

int main()
{

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++)
    {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++)
        {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++)
    {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];

            if (j != result[i].size() - 1)
            {
                cout << " ";
            }
        }

        if (i != result.size() - 1)
        {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

/**
 * Tôi tự làm, theo sự nhớ
 */
// class Node
// {
// public:
//     Node *left;
//     Node *right;
//     int data;
//     Node(int x) : left(nullptr), right(nullptr), data(x) {};
// };
// void inOrder(Node *curNode, vector<int> &vec_res)
// {
//     if (curNode == nullptr)
//         return;
//     inOrder(curNode->left, vec_res);
//     vec_res.push_back(curNode->data);
//     inOrder(curNode->right, vec_res);
// }
// void swapNode(Node *node, int k, int level)
// {
//     if (node == nullptr || (node->left == nullptr && node->right == nullptr))
//         return;
//     if (level % k == 0)
//     {
//         swap(node->left, node->right);
//     }
//     swapNode(node->left, k, level + 1);
//     swapNode(node->right, k, level + 1);
// }
// vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
// {
//     // 1. chuyển vector to binary search tree
//     Node *root = new Node(1);
//     queue<Node *> que;
//     que.push(root);
//     for (int i = 0; i < indexes.size(); i++)
//     {
//         Node *cur = que.front();
//         que.pop();
//         if (indexes[i][0] != -1)
//         {
//             root->left = new Node(indexes[i][0]);
//             que.push(root->left);
//         }
//         if (indexes[i][1] != -1)
//         {
//             root->right = new Node(indexes[i][1]);
//             que.push(root->right);
//         }
//     }
//     // 2. swap & chuyển lại về vector theo in-order
//     vector<vector<int>> result;
//     for (int i = 0; i < queries.size(); i++)
//     {
//         vector<int> res;
//         swapNode(root, queries[i], 1);
//         inOrder(root, res);
//         result.push_back(res);
//     }
//     return result;
// }
