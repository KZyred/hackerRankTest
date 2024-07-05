#include <iostream>
#include <cstring>
#include <utility> // std::move

class MyString
{
public:
    char *data;

    // Constructor
    MyString(const char *str)
    {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Destructor
    ~MyString()
    {
        delete[] data;
    }

    // Copy Constructor
    MyString(const MyString &other)
    {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        std::cout << "Copy constructor called\n";
    }

    // Move Constructor
    MyString(MyString &&other) noexcept : data(other.data)
    {
        other.data = nullptr;
        std::cout << "Move constructor called\n";
    }

    // Copy Assignment Operator
    MyString &operator=(const MyString &other)
    {
        if (this != &other)
        {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
            std::cout << "Copy assignment operator called\n";
        }
        return *this;
    }

    // Move Assignment Operator
    MyString &operator=(MyString &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data;        // Free existing resource
            data = other.data;    // Transfer ownership2
            other.data = nullptr; // Leave source in a valid state
            std::cout << "Move assignment operator called\n";
        }
        return *this;
    }

    void print() const
    {
        if (data)
            std::cout << data << std::endl;
        else
            std::cout << "Empty" << std::endl;
    }
};

int main()
{
    MyString str1("Hello");
    MyString str2("World");

    std::cout << "Before move assignment:\n";
    std::cout << "str1: ";
    str1.print();
    std::cout << "str2: ";
    str2.print();

    str2 = std::move(str1); // Move assignment

    std::cout << "After move assignment:\n";
    std::cout << "str1: ";
    str1.print(); // str1 is now empty
    std::cout << "str2: ";
    str2.print(); // str2 has taken ownership of the resource from str1

    return 0;
}
