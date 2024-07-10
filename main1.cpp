#include <iostream>
#include <thread>
#include <mutex>
#include <string>
using namespace std;

std::mutex taskMutex;
void printText(const string &str)
{
    for (int i = 0; i < 5; i++)
    {
        try
        {
            // taskMutex.lock();
            lock_guard<mutex> lock_guard(taskMutex);
            cout << str[0] << str[1] << str[2] << endl;
            throw exception();
            // taskMutex.unlock();
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
        }
    }
}

int main()
{
    thread thr1(printText, "abc");
    thread thr2(printText, "def");
    thread thr3(printText, "ghi");

    thr1.join();
    thr2.join();
    thr3.join();

    return 0;
}
