#include <thread>
#include <iostream>

using namespace std;

class thread_guard
{
    thread thr;

public:
    explicit thread_guard(thread &&thr) : thr(std::move(thr))
    {
        cout << "thread_guard constructor called" << std::endl;
    };
    thread_guard(){};
    thread_guard(thread_guard &&other) noexcept
    {
        thr = move(other.thr);
        // thr = other.thr; // error: do thread lib chưa có "move operator"
    };

    ~thread_guard()
    {
        cout << "thread_guard deconstructor called" << std::endl;

        if (thr.joinable())
        {
            thr.join();
        }
    }
    thread_guard(const thread_guard &) = delete;
    thread_guard &operator=(const thread_guard &) = delete;
};

void hello()
{
    cout << "Hello, tôi đang chào" << endl;
}

int main()
{
    try
    {
        // cách 1: dùng constructor là chân ái
        thread thr(hello);
        thread_guard tguard(std::move(thr));

        // cách 2: move constructor: không ổn, move chỉ move 2 đối tượng giống nhau thôi
        // chưa hiểu bản chất vấn đề rồi
        // thread_guard t2guard;
        // thread_guard tguard = std::move(t2guard);

        /**
         *
         *
         * Hãy cmt or uncmt dòng throw để thấy điều thú vị với decontructor
         *
         *
         */
        // throw std::exception();
        // while (true)
        // {
        // }
    }
    catch (std::exception &e)
    {
        cout << "Ex: " << e.what() << std::endl;
    }
}