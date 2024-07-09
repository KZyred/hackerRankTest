#include <iostream>
#include <stdio.h>

int global = 100; // global is lvalue while 100 is rvalue

int& setValue() { // it return a lvalue
	return global;
}

int main() {
	int a = 100; // a is lvalue, 100 is rvalue
	
	const int& x = 666; // x is const reference
	const int* y = &x; // &x is rvalue, y lvalue
	setValue() = 2; // this work cause in assignment, on the left is lvalue
	
	
//	int&& k = 4; // rvalue reference
//	k += 1;
	
	return 0;
}
