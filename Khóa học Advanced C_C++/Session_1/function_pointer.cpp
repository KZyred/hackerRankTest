/**
 * CON TRỎ HÀM
 *
 * Delegate là một khái niệm quen thuộc trong C#, . NET,
 * nó tương tự như con trỏ hàm trong C++
 */
#include <iostream>

void fun(int a)
{
	std::cout << "value of a is " << a << std::endl;
}

void wrap(void (*func)(int))
{
	fun(68);
}
int main()
{
	// gọi trực tiếp
	void (*func_pointer)(int) = fun; // có vẻ rất giống với delegate
	func_pointer(20);
	// gọi qua hàm
	wrap(fun);

	return 0;
}
