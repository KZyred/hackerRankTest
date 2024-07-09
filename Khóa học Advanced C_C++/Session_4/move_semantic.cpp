#include <iostream>
#include <string>

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
	void reset(); 								// reset to valid state
};

Wrapper::Wrapper(const Wrapper & rhs) { // 3
	cout << "3. copy ctor\n";
 	m_data = new int[rhs.m_size]; // this line is identical to line in copy assigment operator
		
	std::copy(rhs.m_data, rhs.m_data + rhs.m_size, m_data);
	m_size = rhs.m_size;
}

Wrapper::~Wrapper(){ // 4
	cout << "4. dtor\n";
	delete[] m_data;
	m_size = 0;		
}

Wrapper::Wrapper(Wrapper && rhs) noexcept { // 5
	cout << "5. move ctor\n";
	if (this != &rhs){
		m_data = rhs.m_data;
		m_size = rhs.m_size;
		rhs.reset();
	}
	
}
Wrapper::operator std::string () { // 6
	cout << "6. conversion operator\n";
	return "hello";
}

Wrapper & Wrapper::operator =(const Wrapper & rhs) { // 7
	cout << "7. copy operator\n";
	if (this != &rhs){
		delete[] m_data;
		m_data = new int[rhs.m_size]; // this is copy operator so re-allocate m_data is needed
		
		std::copy(rhs.m_data, rhs.m_data + rhs.m_size, m_data);
		m_size = rhs.m_size;
	}
	return *this;
}

Wrapper & Wrapper::operator =(Wrapper && rhs) noexcept { // 8
	cout << "8. move operator\n";
	if (this != &rhs){
		delete[] m_data; // we should deallocate current memory which is held in m_data
		// m_data = new int[rhs.m_size]; // this line is no need cause we poiter to rvalue reference instead
		
		m_data = rhs.m_data;
		m_size = rhs.m_size;
	
		rhs.reset();
	}
	return *this;
}
void Wrapper::reset(){
	m_data = nullptr;
	m_size = 0;
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
