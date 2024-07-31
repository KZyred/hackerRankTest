/*
   Nhân thấy:
   1. biết so sánh hai kí tự thep alphabet
   2. cách sử dụng sort(players.begin(), players.end(), compare);
    - sort có điều kiện.
    - với đối số thứ 3 nhận là true or false
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Player
{
    int score;
    string name;
};

class Checker
{
public:
    // complete this method
    // 1. Sắp xếp điểm giảm dần, cùng điểm -> sắp xếp theo alphabetically
    // return:
    // 1: nếu a > b
    // 0: nếu a = b
    //-1: nếu a < b
    static int comparator(Player a, Player b)
    {
        if (a.score > b.score)
        {
            return 1;
        }
        else if (a.score < b.score)
        {
            return -1;
        }
        else if (a.score == b.score)
        {
            if (a.name == b.name)
            {
                return 0;
            }
            else if (a.name < b.name)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        return 0;
    }
};

bool compare(Player a, Player b)
{
    if (Checker::comparator(a, b) == -1)
        return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    vector<Player> players;
    string name;
    int score;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> score;
        Player player;
        player.name = name, player.score = score;
        players.push_back(player);
    }
    sort(players.begin(), players.end(), compare);
    for (int i = 0; i < players.size(); i++)
    {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}