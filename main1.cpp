#include <stdio.h>

struct S
{
    char a;
    int b : 5;
    int c : 11;
          : 0;
          int d : 8;
          struct
          {
              int ee : 8;
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
