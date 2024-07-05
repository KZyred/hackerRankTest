#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
class A
{
public:
    std::string s;
    // khởi tạo mặc định
    A() : s("test") {}
    // copy const constructor
    A(const A &o) : s(o.s) { std::cout << "move failed!\n"; }

    // move constructor
    A(A &&o) : s(std::move(o.s)) {}

    // copy assignment operator
    A &operator=(const A &other)
    {
        s = other.s;
        std::cout << "copy assigned\n";
        return *this;
    }

    // move assignment operator
    A &operator=(A &&other)
    {
        s = std::move(other.s);
        std::cout << "move assigned\n";
        return *this;
    }
};

A f(A a) { return a; }

class B : public A
{
public:
    std::string s2;
    int n;
    // implicit move assignment operator B& B::operator=(B&&)
    // calls A's move assignment operator
    // calls s2's move assignment operator
    // and makes a bitwise copy of n
};

class C : public B
{
public:
    ~C() {} // destructor prevents implicit move assignment
};

class D : public B
{
public:
    D() {}
    ~D() {}                       // destructor would prevent implicit move assignment
    D &operator=(D &&) = default; // force a move assignment anyway
};

int main()
{
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = std::move(v1);

    cout << "v1: ";
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << "\n";
    cout << "v2: ";
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << "\n";
}