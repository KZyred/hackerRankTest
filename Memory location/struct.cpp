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

// Size of struct S: 20 bytes
// Address of obj.a: 00007FF7139A7030
// Size of obj.a: 1 bytes
// Size of obj.e: 8 bytes