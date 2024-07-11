#include <iostream>
#include <thread>

using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Test init done" << endl;
    }
    void func()
    {
    }
};
void process()
{
    static Test pTest; // static local variable
    pTest.func();
}
int main()
{
    thread thr1(process);
    thread thr2(process);
    thr1.join();
    thr2.join();
}
