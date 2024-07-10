#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;
using namespace literals;

class Vector
{
    mutex mut;
    vector<int> vec;

public:
    void puckBack(const int &ele)
    {
        mut.lock();
        vec.push_back(ele);
        mut.unlock();
    }
    void print()
    {
        mut.lock();
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << ",";
        }
        cout << endl;
        mut.unlock();
    }
};
void func(Vector &vec)
{
    for (int i = 1; i <= 5; i++)
    {
        vec.puckBack(i);
        this_thread::sleep_for(100ms);
        vec.print();
    }
};

int main()
{
    Vector vec;
    // thread thr1(func, (Vector &)vec); // thiếu std::ref -> not run
    thread thr1(func, std::ref(vec)); // thiếu std::ref -> not run
    thread thr2(func, std::ref(vec));
    thread thr3(func, std::ref(vec));

    thr1.join();
    thr2.join();
    thr3.join();
}