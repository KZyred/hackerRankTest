#include <iostream>

using namespace std;

class Wrapper{
private:
	int* m_data;
	size_t m_size;

public:
	Wrapper() : m_data(nullptr), m_size(0) {	// 1. default constructor
		cout << "1. default ctor\n";
	}
	Wrapper(size_t size) { 						// 2. constructor with parameter
		cout << "2. ctor with parameter\n";
		m_data = new int[size];
		m_size = size;
	}
	Wrapper(const Wrapper &); 					// 3. copy constructor
	~Wrapper(); 								// 4. destructor
	Wrapper(Wrapper &&) noexcept; 				// 5. move constructor
	operator std::string (); 					// 6. conversion operator
	Wrapper & operator = (const Wrapper & ); 	// 7. copy assignment operator
	Wrapper & operator = (Wrapper &&) noexcept; // 8. move assigment operator
	void reset(); 								// reset object to default state
};

Wrapper::Wrapper(const Wrapper & rhs) { // 3
	// implement here
}

Wrapper::~Wrapper(){ // 4
	// implement here	
}

Wrapper::Wrapper(Wrapper && rhs) noexcept { // 5
	// implement here
}
Wrapper::operator std::string () { // 6
	// implement here
}

Wrapper & Wrapper::operator =(const Wrapper & rhs) { // 7
	// implement here
}

Wrapper & Wrapper::operator =(Wrapper && rhs) noexcept { // 8
	// implement here
}
void Wrapper::reset(){
	// implement here
}

int main(){
	Wrapper w1(100); 				// 2. constructor with parameter
	Wrapper w2 = w1; 				// 3. copy constructor
	Wrapper w3; 					// 1. default constructor
	w3 = w2; 						// 7. copy assigment operator
	Wrapper w4 = (Wrapper &&) w2; 	// 5. move constructor
	w4 = std::move(w3); 			// 8. move assignment operator
	std::string k = w4; 			// 6. conversion operator
	cout << k << endl;
	return 0;
}
