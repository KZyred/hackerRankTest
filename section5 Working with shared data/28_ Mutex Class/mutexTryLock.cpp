#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::mutex mutexTask;
void Task1()
{
    std::cout << "Task1 trying to lock the mutex" << std::endl;
    mutexTask.lock();
    std::cout << "Task1 has locked the mutex" << std::endl;
    std::this_thread::sleep_for(500ms);
    std::cout << "Task1 is unlocking the mutex" << std::endl;
    mutexTask.unlock();
}
void Task2()
{
    std::this_thread::sleep_for(100ms);
    std::cout << "Task2 trying to lock the mutex" << std::endl;
    while (!mutexTask.try_lock())
    {
        std::cout << "Task2 could not lock the mutex" << std::endl;
        std::this_thread::sleep_for(100ms);
    }
    std::cout << "Task2 has locked the mutex" << std::endl;
    mutexTask.unlock();
}

int main()
{
    std::thread thr1(Task1);
    std::thread thr2(Task2);

    thr1.join();
    thr2.join();
}