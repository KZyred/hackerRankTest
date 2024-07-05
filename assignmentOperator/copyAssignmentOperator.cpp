#include <algorithm>
#include <iostream>
#include <memory>
#include <string>

struct A
{
    int n;
    std::string s1;

    A() = default;
    A(A const &) = default;

    // user-defined copy assignment (copy-and-swap idiom)
    // toán tử copy do người dùng tự định nghĩa (thành ngữ sao chép và trao đổi)
    A &operator=(A other)
    {
        std::cout << "copy assignment of A\n";
        std::swap(n, other.n);
        std::swap(s1, other.s1);
        return *this;
    }
};

struct B : A
{
    std::string s2;
    // implicitly-defined copy assignment
};

struct C
{
    std::unique_ptr<int[]> data;
    std::size_t size;

    // user-defined copy assignment (non copy-and-swap idiom)
    // note: copy-and-swap would always reallocate resources

    // gán bản sao do người dùng xác định (thành ngữ không sao chép và trao đổi)
    // do: copy-and-swap sẽ luôn phân bổ lại tài nguyên, tạo ra thêm tài nguyên
    // , gây tốn bộ nhớ, trung gian cho bên thứ ba nên hiệu suất kém
    C &operator=(const C &other)
    {
        if (this != &other) // not a self-assignment
        {
            if (size != other.size) // resource cannot be reused
            {
                data.reset(new int[other.size]);
                size = other.size;
            }
            std::copy(&other.data[0], &other.data[0] + size, &data[0]);
        }
        return *this;
    }
};

int main()
{
    // thực hiện copy từ a2 vào a1
    A a1, a2;
    std::cout << "a1 = a2 calls ";
    a1 = a2; // user-defined copy assignment

    // thực hiện copy từ b2 vào b1
    B b1, b2;
    b2.s1 = "foo";
    b2.s2 = "bar";
    std::cout << "b1 = b2 calls ";
    b1 = b2; // implicitly-defined copy assignment

    std::cout << "b1.s1 = " << b1.s1 << "; b1.s2 = " << b1.s2 << '\n';
}