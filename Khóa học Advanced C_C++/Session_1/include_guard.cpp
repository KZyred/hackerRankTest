/**
 * Một ví dụ điển hình về việc include vòng tròn với file include_guard.cpp
 *
 * #include A
 * trong inclu A lại có inclu B
 * trong inclu B lại có inclu A
 */
#include <cstdio>
#include <iostream>
#include "includeA_B.h"

int main()
{
	puts("Hello World!");
	return 0;
}
