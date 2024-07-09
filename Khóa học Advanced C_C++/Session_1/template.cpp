#include <iostream>
#include <vector>

template <class T>
T max(T x, T y) {
	return (x > y ? x: y);
}

class A {
	public:
	A(){
	};
	A(int _value){
		value = _value;
	};
	
	int getValue(){
		return value;
	}
	private:
		int value;
};

int main() {
	int u = 4, v = 8;
	float a = 3.4f, b = 5.6f;
	std::cout << "number bigger in " << u << " and " << v << " is: " << max(u,v) << std::endl;
	std::cout << "number bigger in " << a << " and " << b << " is: " << max<float>(a,b) << std::endl;
	
	std::vector<int> vec_int;
	std::vector<double> vec_double(4, 130);
	std::vector<A> vec_A;
	
	vec_A.push_back(3);
	vec_A.push_back(10);
	vec_A.push_back(20);
	
	for (std::vector<A>::iterator it = vec_A.begin(); it != vec_A.end(); ++it){
		std::cout << it->getValue() << std::endl;
	}
	
	for (std::vector<double>::iterator it = vec_double.begin(); it != vec_double.end(); ++it){
		std::cout << *it << std::endl;
	}
	return 0;
}
