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
        taskMutex.lock();
        cout << str[0] << str[1] << str[2] << endl;
        taskMutex.unlock();
    }
}
/**
 * câu hỏi đặt ra: làm thế nào để biết thr1 thực thi trước hay thr2 or thr3 thực thi trước
 *
 * do khi in kết quả ra màn hình: ngẫu nhiên in ra thứ tự rất khác nhau:
 * không tuân theo quy tắc abc -> def -> ghi mà các luồng join vào (vẫn tuân theo mutex lock)
 */
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
