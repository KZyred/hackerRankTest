#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Test
{
public:
    Test()
    {
        cout << "test init done" << endl;
    }
    void func()
    {
    }
};

/**
 * tôi có 2 luồng
 *  cùng khởi tạo 1 biến
 * yêu cầu khởi tạo 1 lần, đến khi hoàn thành
 */
std::once_flag onceFlag;
Test *test = nullptr;
void process()
{
    std::call_once(onceFlag, []()
                   { test = new Test(); }); // gọi 1 lần, và gọi cho tới khi hoàn thành
    if (test != nullptr)
    {
        test->func();
    }
}
int main()
{
    thread thr1(process);
    thread thr2(process);
    thr1.join();
    thr2.join();
}