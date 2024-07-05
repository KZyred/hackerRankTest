// CPP program to
// illustrate how to avoid
// memory leak
#include <iostream>
using namespace std;

// function to see memory handling
void func_to_handle_mem_leak()
{
    int *ptr = new int(5);

    // body

    // Now delete pointer ptr using delete
    delete (ptr);
}

// Driver code
int main()
{

    // Call function to handle
    // the memory leak
    func_to_handle_mem_leak();

    return 0;
}
