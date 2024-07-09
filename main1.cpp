#include <iostream>
using namespace std;
class testExplicit
{
public:
    explicit testExplicit()
    // testExplicit()
    {
        cout << "Explicit done" << endl;
    }
    testExplicit(testExplicit &&other)
    {
        cout << "Move Constructor called" << endl;
    }
    testExplicit(testExplicit &other)
    {
        cout << "Copy Constructor called" << endl;
    }
};

int main()
{
    testExplicit a;
    return 0;
}
