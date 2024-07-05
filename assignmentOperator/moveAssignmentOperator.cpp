#include <iostream>
#include <string>
#include <utility>

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
    A a1, a2;
    std::cout << "Trying to move-assign A from rvalue temporary\n";
    a1 = f(A()); // move-assignment from rvalue temporary
    std::cout << "Trying to move-assign A from xvalue\n";
    a2 = std::move(a1); // move-assignment from xvalue

    std::cout << "\nTrying to move-assign B\n";
    B b1, b2;
    std::cout << "Before move, b1.s = \"" << b1.s << "\"\n";
    std::cout << "Before move, b2.s = \"" << b2.s << "\"\n";
    b2 = std::move(b1); // calls implicit move assignment
    std::cout << "After move, b1.s = \"" << b1.s << "\"\n";
    std::cout << "After move, b2.s = \"" << b2.s << "\"\n";

    std::cout << "\nTrying to move-assign C\n";
    C c1, c2;
    c2 = std::move(c1); // calls the copy assignment operator

    std::cout << "\nTrying to move-assign D\n";
    D d1, d2;
    d2 = std::move(d1);
}