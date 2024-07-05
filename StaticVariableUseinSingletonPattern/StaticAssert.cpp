#include <iostream>
#include <type_traits>
template <typename T>
void checkType()
{
    static_assert(std::is_integral<T>::value, "T must be an integral type");
}
int main()
{
    checkType<int>(); // OK
    // checkType<float>(); // Compile-time error
    return 0;
}
