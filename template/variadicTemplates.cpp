#include <iostream>

// Base case
void print()
{
    std::cout << "No more arguments" << std::endl;
}

// sử dụng đệ quy để in ra cho tới khi hết đối số truyền vào
template <typename T, typename... Args>
void print(T first, Args... args)
{
    std::cout << first << " ";
    print(args...);
}

int main()
{
    print(1, 2.5, "Hello", 'A');
    return 0;
}
