#include <iostream>

void fun(int a){
	std::cout << "value of a is " << a << std::endl;
}

void wrap (void (*func)(int)) {
	fun(68);
}
int main(){
	void (*func_pointer) (int) = fun;
	
	func_pointer(20);
	wrap(fun);
	
	return 0;
}
