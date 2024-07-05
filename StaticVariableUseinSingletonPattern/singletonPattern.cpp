#include <iostream>

class Singleton
{
private:
    static Singleton *instance;
    Singleton() {} // Private constructor

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage()
    {
        std::cout << "Singleton instance" << std::endl;
    }
};

Singleton *Singleton::instance = nullptr;

int main()
{
    Singleton *s = Singleton::getInstance();
    s->showMessage();

    return 0;
}
