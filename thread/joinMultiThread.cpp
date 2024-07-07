#include <iostream>
#include <cstring>
#include <vector>
#include <thread>
using namespace std;
void func()
{
    this_thread::sleep_for(3s);
    cout << "hello, threaa" << endl;
}
void func2()
{
    this_thread::sleep_for(1s);
    cout << "hi, threaa" << endl;
}
int main()
{
    thread thr(func);
    thread thr2(func2);
    thr.join();
    thr2.join();
    cout << "no, threaa" << endl;

    return 0;
}
