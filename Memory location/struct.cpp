#include <stdio.h>

struct S
{
    char a;     // memory location #1
    int b : 5;  // memory location #2
    int c : 11, // memory location #2 (continued)
        : 0,
        d : 8; // memory location #3  ~ ngang với int d : 8;
    struct
    {
        int ee : 8; // memory location #4
        char aa;
    } e;
} obj;
int main()
{
    printf("Size of struct S: %zu bytes\n", sizeof(obj));
    printf("Address of obj.a: %p\n", (void *)&obj.a);
    printf("Size of obj.a: %zu bytes\n", sizeof(obj.a));
    printf("Size of obj.e: %zu bytes\n", sizeof(obj.e));
    // printf("Size of obj.e.ee: %zu bytes\n", sizeof(obj.e.ee));
    return 0;
}

// Nhận xét: kích thước của struct sẽ được tính bằng không gian chứa phần tử lớn nhất
// nhân với số phần tử được cấp phát

// chú ý:
/**
 * int b : 5
 * Bạn đang khai báo một trường bit (bit-field)
 *
int: Kiểu dữ liệu cơ sở của trường bit. Trường bit b sẽ sử dụng kiểu int làm cơ sở.
b: Tên của trường bit.
: 5: Số lượng bit được gán cho trường bit này. Ở đây, b sẽ sử dụng 5 bit.



 */

// Size of struct S: 20 bytes
// Address of obj.a: 00007FF7139A7030
// Size of obj.a: 1 bytes
// Size of obj.e: 8 bytes

/**
#include <stdio.h>

struct S {
    unsigned int a : 3;  // 3 bits for 'a'
    unsigned int b : 5;  // 5 bits for 'b'
    unsigned int c : 6;  // 6 bits for 'c'
};

int main() {
    struct S s = {1, 15, 31};  // Initializing the bit fields

    printf("a: %u\n", s.a);  // Output: 1
    printf("b: %u\n", s.b);  // Output: 15
    printf("c: %u\n", s.c);  // Output: 31

    s.b = 31;  // Trying to assign a value larger than 5 bits
    printf("b: %u\n", s.b);  // Output: 31 % (2^5) = 31 % 32 = 31

    s.b = 32;  // Trying to assign a value larger than 5 bits
    printf("b: %u\n", s.b);  // Output: 32 % (2^5) = 32 % 32 = 0

    return 0;
}
 */