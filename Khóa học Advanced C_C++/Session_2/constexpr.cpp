#include <stdio.h>

constexpr int power2(int _value) {
	return _value * _value;
}

constexpr int x = 3;

class A {
	constexpr static int a = 3;
	int b;
	
	public:
		A(){
		};
	constexpr A(int _b) : b(_b){
		//printf("constexpr constructor is called\n");
		//	b = _b;
		};
	constexpr int getB() {
		return b;
	}
};

int main() {
	const int a = 3;
	int b = a + 4;
		
	constexpr A value(x);
	const A a_value(b);
	
	printf("consexpr return function value is: %d, b value is: %d\n", power2(a), a_value.getB());
	
	return 0;
}
