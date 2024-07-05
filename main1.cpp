#include <iostream>
template <class T>
// template <typename T>

void custom_add(T val1, T val2)
{
    std::cout << "Addition = " << (val1 + val2) << std::endl;
}

// class StudentFee : T
// {
// public:
//     void annualFees()
//     {
//         this->fees();
//     }
// };
// class EngStudent
// {
// public:
//     void fees()
//     {
//         std::cout << "EngStudent Fees = INR 70,000" << std::endl;
//     }
// };
// class MbaStudent
// {
// public:
//     void fees()
//     {
//         std::cout << "MbaStudent Fees = INR 95,000" << std::endl;
//     }
// };

int main()
{
    // StudentFee<EngStudent> engStudent;
    // StudentFee<MbaStudent> mbaStudent;
    // engStudent.annualFees();
    // mbaStudent.annualFees();
    int *p = new int(1);

    custom_add<int>(3, 5);              // type specifier <int> present
    custom_add<float>(3.2, 4.5);        // type specifier <float> present
    custom_add<double>(3.2123, 4.5456); // type specifier <float> present
    return 0;
}